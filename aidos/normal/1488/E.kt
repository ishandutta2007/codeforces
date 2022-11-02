
class Seg{
    var a = ArrayList<Int>()
    fun resize(n:Int) {
        while(a.size < 4 * (n + 2)) {
            a.add(0)
        }
    }
    fun get(v:Int, tl:Int, tr:Int, l:Int, r:Int): Int{

        if(tl > r || tr < l) return 0
        if(l <= tl && tr <= r) return a[v]
        var mid = (tl + tr)/2
        return Math.max(this.get(v * 2, tl, mid, l, r), this.get(v * 2 + 1, mid + 1, tr, l, r))
    }
    fun update(v:Int, tl:Int, tr:Int, pos:Int, va:Int) {
        if(tl == tr) {
            a[v] = va
        }else {
            var mid = (tl + tr)/2
            if(pos <= mid) {
                this.update(v * 2, tl, mid, pos, va)
            } else {
                this.update(v * 2 + 1, mid + 1, tr, pos, va)
            }
            a[v] = Math.max(a[v * 2], a[v * 2 + 1])
        }
    }
}

fun solve() {
    //var (n, s) = readLine()!!.split(" ").map{it.toLong()}
    var n = readLine()!!.toInt()
    var a = readLine()!!.split(" ").map{it.toInt()}
    var last = IntArray(n + 1)
    var seg = Seg()
    seg.resize( n + 1)

    for (i in 0 until n + 1) {
        last[i] = 0
    }
    for(i in 0 until n) {
        if(last[a[i]] != 0) {
            var cur = seg.get(1, 0, n, last[a[i]] + 1, i)
            seg.update(1, 0, n, last[a[i]], cur + 2)
        }
        seg.update(1, 0, n, i+1, 1)
        last[a[i]] = i + 1
    }
    println(seg.get(1, 0, n, 0, n))
}


fun main(args: Array<String>) {
    //println("Hello World!")
    var t = 1
    t = readLine()!!.toInt()
    for (i in 0 until t) {
        solve()
    }
}