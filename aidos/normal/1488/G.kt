
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
        return Math.max(this.get(v * 2, tl, mid, l, r), this.get(v * 2 + 1, mid + 1, tr, l, r))
    }
    fun getPos(v:Int, tl:Int, tr:Int, va:Long): Int {
        if(tl == tr) {
            return tl
        }
        var mid = (tl + tr)/2
        if(t[v * 2] == va) return this.getPos(v * 2, tl, mid, va)
        return this.getPos(v * 2 + 1, mid + 1, tr, va)
    }
    fun update(v:Int, tl:Int, tr:Int,  l:Int, r:Int, va:Int) {
        this.push(v, tl, tr)
        if(tl > r || tr < l) return
        if(l <= tl && tr <= r) {
            a[v] = va
            t[v] = va.toLong()
            return
        }

        var mid = (tl + tr)/2
        this.update(v * 2, tl, mid, l, r, va)
        this.update(v * 2 + 1, mid + 1, tr, l, r, va)

        t[v] = Math.max(t[v * 2], t[v * 2 + 1])

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
    var seg = Seg()
    //seg.resize(n + 1)
    var ans = IntArray(n)
    var cur = IntArray(n + 1)
    for(i in 1 until n + 1) {
        var j = i + i
        while(j <= n) {
            cur[j]++
            j += i
        }
    }
    var div = ArrayList<ArrayList<Int>>()
    var maxs = ArrayList<ArrayList<Int>>()
    for (i in 0 until  n + 1) {
        div.add(ArrayList<Int>())
    }
    for(i in 0 until 2 * n + 2)
        maxs.add(ArrayList<Int>())

    for(i in 1 until n + 1) {
        var j = i + i
        while(j <= n) {
            div[j].add(i)
            j += i
        }
    }
    ///println(maxs.size)

    for(i in 1 until n + 1) {
        maxs[cur[i] + n].add(i)
    }
    var curPos = 2 * n
    //println("OK")
    var curSum = 0
    for(i in 0 until n) {
        while(true) {
            //println(curPos)
            //println(maxs[curPos].size)

            if(maxs[curPos].size == 0) {
                curPos--
                continue
            }
            var last = maxs[curPos][maxs[curPos].size-1]
            //println(last)
            //println(cur[last])
            if(cur[last] != curPos - n) {
                //println(maxs[curPos])
                maxs[curPos].removeAt(maxs[curPos].size-1)
                //println(maxs[curPos])
            } else {
                break
            }
        }
        var pos = maxs[curPos].last()
        curSum += cur[pos]
        ans[i] = curSum
        for(j in div[pos]){
            cur[j]--
            if(cur[j] >= -n) {
                maxs[cur[j] + n].add(j)
            }
        }
        var j = pos + pos

        while(j <= n) {
            cur[j]--
            if(cur[j] >= -n) {
                maxs[cur[j] + n].add(j)
            }
            j += pos
        }
        cur[pos] = -1000000000
    }
    println(ans.joinToString(" "))
}


fun main(args: Array<String>) {
    //println("Hello World!")
    var t = 1
    //t = readLine()!!.toInt()
    for (i in 0 until t) {
        solve()
    }
}