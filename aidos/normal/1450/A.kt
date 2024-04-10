
fun solve(){
    readLine()!!
    var a = readLine()!!
    var b = a.toCharArray()
    b.sort()
    println(b.joinToString(""))

}

fun main() {
    var t = readLine()!!.toInt()
    for (i in 0 until t) {
        solve()
    }
}