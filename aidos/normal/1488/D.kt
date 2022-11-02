
class Obj : Comparable<Obj>{
    var l: Int = 0
    var r: Int = 0
    var ind: Int = 0
    override fun compareTo(other: Obj): Int = this.l.compareTo(other.l)
}

fun solve() {
    var (n, s) = readLine()!!.split(" ").map{it.toLong()}
    var l = 1L
    var r = s
    var ans = 0L
    while(l <= r) {
        var mid = (l + r)/2
        var x = mid
        var days = 0
        var sum = s
        while(x > 1 && days < n && sum > 0) {
            sum -= x
            x = (x + 1)/2
            days++
        }
        if(sum >= n - days){
            ans = mid
            l = mid+1
        } else {
            r = mid-1
        }
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