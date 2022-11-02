
class Obj : Comparable<Obj>{
    var l: Int = 0
    var r: Int = 0
    var ind: Int = 0
    override fun compareTo(other: Obj): Int = this.l.compareTo(other.l)
}

fun solve() {
    var (x, y) = readLine()!!.split(" ").map{it.toLong()}
    var ans = 0
    var cnt = 0
    while(x <= y) {
        x *= 10
        cnt += 1
    }
    for (i in 0 until cnt + 1) {
        while(y >= x) {
            y -= x
            ans++
        }
        x/=10
    }
    println(ans + y)
}


fun main(args: Array<String>) {
    //println("Hello World!")
    var t = 1
    t = readLine()!!.toInt()
    for (i in 0 until t) {
        solve()
    }
}