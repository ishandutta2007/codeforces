
fun solve() {
    var n = readLine()!!.toInt()
    var s = readLine()!!
    var cur = 0
    var ans = 0
    for(i in 0 until n) {
        if(s[i] == 'x') {
            cur += 1
        } else {
            cur = 0
        }
        if(cur == 3) {
            cur--
            ans++
        }
    }
    println(ans)
}


fun main(args: Array<String>) {
    //println("Hello World!")
    var t = 1
    //t = readLine()!!.toInt()
    for (i in 0 until t) {
        solve()
    }
}