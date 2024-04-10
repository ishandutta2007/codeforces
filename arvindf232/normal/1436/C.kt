/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
 */
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter

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
fun getLine():List<Long>{
    return reading.jin.readLine().split(" ").map { it.toLong() }
}
fun getString():String{
    return reading.jin.readLine()
}


inline fun cases(ask:()->Unit){
    val t = getInt()
    repeat(t){
        ask()
    }
}

val p = 1000000007L
infix fun Long.modM(b:Long):Long{
    return (this * b) % p
}
fun fact(b:Long):Long{
    var ret = 1L
    for(i in 1..b){
        ret = ret modM i
    }
    return ret
}
fun pow(x:Long,e:Long,m:Long):Long{
    var X = x
    var E =e
    var Y = 1L
    while(E > 0){
        if(E % 2 == 0L){
            X = (X * X) % m
            E = E/2
        }else{
            Y = (X * Y) % m
            E = E-1
        }
    }
    return Y
}
fun Long.inverse():Long{
    return pow(this,p-2,p)
}
infix fun Long.choose(b:Long):Long{
    var ret = 1L
    for(i in 1..b){
        ret = ret modM (this-i+1)
//        ret = ret modM ((i).inverse())
    }
    return ret
}



fun main() {
//    println(3L choose 1L)
//    print(pow(2,101,103))


    val (n,x,pos) = getLine()

    var toLeft = 0
    var toRight = 0

    var left = 0L
    var right = n
    while(left < right){
        val middle = (left + right) / 2
        if(middle <= pos){
            if(middle != pos){
                toLeft += 1
            }
            left = middle + 1
        }else{
            if(middle != pos) {
                toRight += 1
            }
            right = middle
        }
    }
    val toLeftOptions = (x-1)
    val toRightOptions = (n-x)

    val result = ((toLeftOptions choose toLeft.toLong()) modM (toRightOptions choose toRight.toLong())) modM (fact(n-1-toLeft - toRight))
    put(result)

    done()
    // Write your solution here
}