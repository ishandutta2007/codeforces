import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import kotlin.system.measureTimeMillis
object IO{
	private const val BS = 1 shl 16
	private const val NC = 0.toChar()
	private val buf = ByteArray(BS)
	private var bId = 0
	private var size = 0
	private var c = NC

	var warningActive = true
	var fakein = StringBuilder()

	private var IN: BufferedInputStream = BufferedInputStream(System.`in`, BS)
	val OUT: PrintWriter = PrintWriter(System.out)

	private val char: Char
		get() {
			while (bId == size) {
				size = IN.read(buf) // no need for checked exceptions
				if (size == -1) return NC
				bId = 0
			}
			return buf[bId++].toChar()
		}

	fun nextInt(): Int {
		var neg = false
		if (c == NC) c = char
		while (c < '0' || c > '9') {
			if (c == '-') neg = true
			c = char
		}
		var res = 0
		while (c in '0'..'9') {
			res = (res shl 3) + (res shl 1) + (c - '0')
			c = char
		}
		return if (neg) -res else res
	}
	fun nextLong(): Long {
		var neg = false
		if (c == NC) c = char
		while (c < '0' || c > '9') {
			if (c == '-') neg = true
			c = char
		}
		var res = 0L
		while (c in '0'..'9') {
			res = (res shl 3) + (res shl 1) + (c - '0')
			c = char
		}
		return if (neg) -res else res
	}
	fun nextString():String{
		val ret = StringBuilder()
		while (true){
			c = char
			if(!isWhitespace(c)){ break}
		}
		ret.append(c)
		while (true){
			c = char
			if(isWhitespace(c)){ break}
			ret.append(c)
		}
		return ret.toString()
	}
	fun isWhitespace(c:Char):Boolean{
		return c == ' ' || c == '\n' || c == '\r' || c == '\t'
	}
}
fun put(aa:Any){ IO.OUT.println(aa)}
fun done(){ IO.OUT.close() }
val getint:Int get() = IO.nextInt()
val getlong:Long get() = IO.nextLong()
val getstr:String get() = IO.nextString()
fun getline(n:Int):IntArray{
	return IntArray(n){getint}
}
fun getlineL(n:Int):LongArray{
	return LongArray(n){getlong}
}

inline fun BinarySearchFirstTrue(l:Int,r:Int,isTrue:(Int)->Boolean):Int?{
    //inclusive
    var L = l
    var R = r
    while(L<R){
        val m = (L + R) shr 1
        if(isTrue(m)){
            R = m
        }else{
            L = m + 1
        }
    }
    return if(isTrue(L)){
        L
    }else{
        if(L == r){
            null
        }else{
            L + 1
        }
    }
}

inline fun BinarySearchLastTrue(l:Int,r:Int,isTrue:(Int)->Boolean):Int?{
    //inclusive
    var L = l
    var R = r
    while(L<R){
       val m = ((L + R) shr 1) + 1
        if(isTrue(m)){ L = m }else{ R = m - 1 }
    }
    return if(isTrue(L)){ L }else{ null }
}


fun main(){
	repeat(1){ _ ->
		val n = getint
		val k = getint
		val a = getint
		val m = getint
		val L = getline(m)
		for(i in 0 until m){
			L[i] --
		}

		var l = 0
		var r = m+1

		val ans = BinarySearchFirstTrue(0,m){mid ->
			val all = BooleanArray(n)
			for(i in 0 until mid) {
				all[L[i]] = true
			}
			var total = 0
			var level = 0
				for(i in 0 until n) {
					if(!all[i]) {
						level++
						if(level >= a) {
							level = -1 
							total++
						}
					} else {
						level = 0
					}
				}
			return@BinarySearchFirstTrue total < k

			}


//		while( l < r) {
//			val mid = (l + r) shr 1
//			val all = BooleanArray(n)
//			for(i in 0 until mid) {
//				all[L[i]] = true
//			}
//			var total = 0
//			var level = 0
//			var ok = false
//			if(mid < m+1){
//				for(i in 0 until n) {
//					if(!all[i]) {
//						level++
//						if(level >= a) {
//							level -= a
//							total++
//						}
//					} else {
//						level = 0
//					}
//				}
//				ok = total < k
//			}
//
//			if(ok) {
////				l = n
//				r = mid
//			}else{
//
//				l = mid+1
//			}
//		}

			if(ans == null) {
				put(-1)
			}else {
				put(ans)
			}





		/*
		ok nvm
		not template
		 */


	}
	done()
}