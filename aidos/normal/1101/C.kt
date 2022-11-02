
class Obj : Comparable<Obj>{
    var l: Int = 0
    var r: Int = 0
    var ind: Int = 0
    override fun compareTo(other: Obj): Int = this.l.compareTo(other.l)
}

fun solve() {
    var n = readLine()!!.toInt()
    var a = ArrayList<Obj>()
    var ans = IntArray(n)
    for(i in 0 until n) {
        var (l, r) = readLine()!!.split(" ").map{it.toInt()}

        var o = Obj()
        o.l = l
        o.r = r
        o.ind = i
        a.add(o)
    }
    a.sort()
    var mx = a[0].r
    var j = -1
    for(i in 1 until n) {
        if(a[i].l <= mx) {

        } else {
            j = i
        }
        if(mx < a[i].r) {
            mx = a[i].r
        }
    }
    if(j == -1) {
        println(-1)
    } else {
        for(i in 0 until n) {
            if(i < j) {
                ans[a[i].ind] = 1
            } else {
                ans[a[i].ind] = 2
            }
        }
        println(ans.joinToString(" "))
    }
}


fun main(args: Array<String>) {
    //println("Hello World!")
    var t = 1
    t = readLine()!!.toInt()
    for (i in 0 until t) {
        solve()
    }
}