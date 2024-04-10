
class Obj : Comparable<Obj>{
    var l: Int = 0
    var r: Int = 0
    var ind: Int = 0
    override fun compareTo(other: Obj): Int = this.l.compareTo(other.l)
}

fun solve() {
    var (n, x, y) = readLine()!!.split(" ").map{it.toInt()}
    if(x > y) {
        var a = x
        x = y
        y = a
    }
    var ans = 3 * n
    for(i in x until y) {
        var le = Math.min((x-1) * 2 + (i-x), (i-x) * 2 + x-1)
        var ri = Math.min((y-i-1) * 2 + n - y, (y-i-1) + 2 * (n-y))
        ans = Math.min(ans, Math.max(le,ri))
    }
    println(ans)
}


fun main(args: Array<String>) {
    //println("Hello World!")
    var t = 1
    t = readLine()!!.toInt()
    for (i in 0 until t) {
        solve()
    }
}