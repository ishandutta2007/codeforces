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

inline fun cases(ask:()->Unit){
    val t = getInt()
    repeat(t){
        ask()
    }
}


tailrec fun gcd(a: Long, b: Long): Long {
    if (b == 0L) {
        return a
    }
    return gcd(b, a % b)
}
fun primeFactors(x:Long):Map<Long,Int>{
    var ret = emptyMap<Long,Int>().toMutableMap()
    var xx = x
    if(x == 1L){
        return ret
    }
    for(i in 2..x){
        if(i * i > x){
            break
        }
        while( xx % i == 0L){
            xx = xx / i
            ret[i] = ret.getOrDefault(i,0) + 1
        }

    }
    if(xx > 1){
        ret[xx] = 1
    }
    return ret
}
fun main() {
    cases{
        val (a,b) = getLine()
        var answer = 0L
        for((p,n) in primeFactors(b)){
            if(a % p != 0L){
                answer = maxOf(answer,a)
            }else{
                var stripped = a
                var used = 0
                while(stripped % p == 0L){
                    stripped = stripped / p
                    used += 1
                }
                repeat(minOf(used,n-1)){
                    stripped = stripped * p
                }
                answer = maxOf(answer,stripped)
            }
        }
        put(answer)
    }
    done()
    // Write your solution here
}