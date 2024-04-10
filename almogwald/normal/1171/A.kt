fun foo(){
    var n = readLine()!!.toInt() 
    println(n/2)
}

fun main(args: Array<String>) {
    var n = readLine()!!.toInt() 
    for (i in 1..n) {
        foo()
    }
}