/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
 */
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*

class reading{
    companion object{
        var jin = BufferedReader(InputStreamReader(System.`in`))
        var pw = PrintWriter(System.out)
    }
}
fun put(aa:Any){
    reading.pw.println(aa)
}
fun done(){
    reading.pw.close()
}

fun getInt():Int{
    return reading.jin.readLine().toInt()
}
fun getLine():List<Int>{
    return reading.jin.readLine().split(" ").map { it.toInt() }
}

inline fun cases(ask:()->Unit){
    val t = getInt()
    repeat(t){
        ask()
    }
}

fun main() {
    // Write your solution herec
    cases{
        val (a,b) = getLine()
        val A = getLine()
        val B = getLine()
        val BS = B.toMutableSet()
        BS.add(0)

        val left = MutableList<Int>(A.size + 1,{0})
        val right = MutableList<Int>(A.size + 1,{0})
        for(i in A.indices){
            if(i > 0){
                left[A[i]] = A[i-1]
            }
            if(i < A.lastIndex){
                right[A[i]] = A[i+1]
            }
        }
        var ret = 1

        for (b in B){
            val times = (if(BS.contains(left[b])) 0 else 1) + ( if(BS.contains(right[b])) 0 else 1)
//            put(times)
            ret = (ret * times) % 998244353
            BS.remove(b)

            right[left[b]] = right[b]
            left[right[b]] = left[b]
        }
        put(ret)
    }
    done()
}