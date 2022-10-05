import kotlin.math.abs
import kotlin.math.min
import kotlin.math.max

/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
 */
fun getInt():Int{
    return readLine()!!.toInt()
}
fun getLine():List<Int>{
    return readLine()!!.split(" ").map { it.toInt() }
}


fun ask(arr:List<Int>):Long{

    var total:Long = 0
    for( i in 1 until arr.size){
        total += abs(arr[i] - arr[i-1])
    }
    var benefit = 0
    for(i in 1 until arr.size-1){
        if(arr[i+1] < arr[i] && arr[i] < arr[i-1]){
            continue
        }
        if(arr[i+1] > arr[i] && arr[i] > arr[i-1]){
            continue
        }


        val get = min(abs(arr[i+1] - arr[i]),abs(arr[i] - arr[i-1]))
        benefit = max(2 * get,benefit)
    }
    benefit = max(benefit,abs(arr[1]-arr[0]))
    benefit = max(benefit,abs(arr[arr.size -1 ]-arr[arr.size - 2]))
    return total - benefit
}

fun main() {
    val t = getInt()
    repeat(t){
        val s = getInt()
        val things = getLine()
        println(ask(things))
    }
    // Write your solution here
}