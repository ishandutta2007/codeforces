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
    // Write your solution here
    val n = getInt()
    val arr = getLine()

    if(arr.size % 2 == 0){
        val total = arr.fold(0,{x,y->x xor y})
        if(total != 0){
            put("NO")
            done()
            return
        }
    }
    put("YES")
    put(2 * ((n-1)/2))
    for(i in 0 until (n-2) step 2){
        put("${i+1} ${i+2} ${i+3}")
    }
    for(i in 0 until (n-2) step 2){
        put("${i+1} ${i+2} ${arr.lastIndex+1}")
    }
    done()

}