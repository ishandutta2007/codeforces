
class Seg{
    var t = ArrayList<Long>()
    var a = ArrayList<Int>()
    fun resize(n:Int) {
        while(t.size < 4 * (n + 2)) {
            t.add(0L)
            a.add(-1)
        }
    }
    fun push(v:Int, tl:Int, tr:Int) {
        if(tl == tr) return
        var mid = (tl + tr)/2
        if(a[v] != -1) {
            a[v * 2] = a[v]
            a[v * 2 + 1] = a[v]
            t[v * 2] = a[v].toLong() * (mid - tl + 1).toLong()
            t[v * 2 + 1] = a[v].toLong() * (tr - mid).toLong()
        }
        a[v] = -1
    }
    fun get(v:Int, tl:Int, tr:Int, l:Int, r:Int): Long{
        this.push(v, tl, tr)
        if(tl > r || tr < l) return 0
        if(l <= tl && tr <= r) return t[v]
        var mid = (tl + tr)/2
        return this.get(v * 2, tl, mid, l, r) + this.get(v * 2 + 1, mid + 1, tr, l, r)
    }
    fun update(v:Int, tl:Int, tr:Int,  l:Int, r:Int, va:Int) {
        this.push(v, tl, tr)
        if(tl > r || tr < l) return
        if(l <= tl && tr <= r) {
            a[v] = va
            t[v] = va.toLong() * (tr - tl + 1).toLong()
            return
        }

        var mid = (tl + tr)/2
        this.update(v * 2, tl, mid, l, r, va)
        this.update(v * 2 + 1, mid + 1, tr, l, r, va)

        t[v] = t[v * 2] + t[v * 2 + 1]

    }
}


class Query:Comparable<Query>{
    var l:Int = 0
    var r:Int = 0
    var ind:Int = 0
    override fun compareTo(other: Query): Int {
        return r.compareTo(other.r)
    }
}

fun solve() {
    //var (n, s) = readLine()!!.split(" ").map{it.toLong()}
    var n = readLine()!!.toInt()
    var a = readLine()!!.split(" ").map{it.toInt()}
    var q = readLine()!!.toInt()
    var seg = Seg()
    seg.resize(n + 1)
    var st = IntArray(n + 1)
    var sz = 0
    var queries = ArrayList<Query>()
    var ans = LongArray(q)
    for(i in 0 until q) {
        var Q = Query();
        var (l, r) = readLine()!!.split(" ").map{it.toInt()}
        Q.l = l
        Q.r = r
        Q.ind = i
        queries.add(Q)
    }
    queries.sort()
    var it = 0
    var prefSum = LongArray(n + 1)
    for(i in 1 until n + 1) {
        prefSum[i] = prefSum[i-1] + a[i-1]
    }

    for(i in 0 until n) {
        while(sz > 0 && a[st[sz-1]] < a[i]) {
            sz--
        }
        if(sz == 0) {
            seg.update(1, 0, n, 0, i, a[i])
        } else {
            seg.update(1, 0, n, st[sz-1] + 1, i, a[i])
        }
        st[sz] = i
        sz++
        while(it < q && queries[it].r == i + 1) {
            ans[queries[it].ind] =  seg.get(1, 0, n, queries[it].l-1, queries[it].r-1)
            it++
        }
    }
    println(ans.joinToString (" " ))
}


fun main(args: Array<String>) {
    //println("Hello World!")
    var t = 1
    //t = readLine()!!.toInt()
    for (i in 0 until t) {
        solve()
    }
}