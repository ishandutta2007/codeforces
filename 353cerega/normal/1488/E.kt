import java.util.*


/*fun cont(len: Int, cnt: Array<Int>): Long
{
    var L = len
    var ans: Long = 1
    cnt.sort()
    for (i in 0..8)
    {
        if (cnt[i]>60) return 2000000000
        for (j in 0..(cnt[i]-1))
        {
            ans *= L
            L--
            ans /= (j+1)
            if (ans>1000000000) return 1000000001
        }
    }
    return ans
}*/




fun main(args: Array<String>) = with(java.util.Scanner(System.`in`))
{
    //var n = nextInt()
    //var map: MutableMap<Int, Int>
    //var numbers: Array<Array<Int>> = Array(3, { Array(5, {0}) })
    //var numbers3: MutableSet<Int> = sortedSetOf(15, 16, 17)
    //var t = nextInt()
    //var n = nextInt()
    //var a = Array(n)
    //{
    //    100-it
    //}
    var t = readLine()!!.toInt()
    for (q in 1..t)
    {
        var n = readLine()!!.toInt()
        val spl = readLine()!!.split(' ').map(String::toInt)
        var a = Array(n)
        {
            Pair(spl[it],it)
        }
        var Q: TreeSet<Int> = sortedSetOf()
        var R = Array(n,{-1})
        a.sortWith(compareBy({it.first}, {it.second}))
        for (i in 0..n-2)
        {
            if (a[i].first==a[i+1].first)
            {
                Q.add(a[i].second)
                R[a[i].second] = a[i+1].second
            }
        }
        var res = Array(n,{0})
        var ans = 1
        var pos: TreeSet<Int> = sortedSetOf()
        var q = Q.descendingSet()
        for (el in q)
        {
            var r = R[el]
            /*print("! ")
            print(el)
            print(" ")
            println(r)*/
            var S = 2
            if (pos.size==0)
            {
                if (el+1<r)
                {
                    S += 1
                }
                pos.add(r)
                res[r] = S
                if (ans<S) ans = S
                continue
            }
            var L = pos.first()
            if (L>r)
            {
                if (el+1<r)
                {
                    S += 1
                }
                res[r] = S
                while (true)
                {
                    var prv = pos.ceiling(r)
                    if (prv==null) break;
                    if (res[prv]<=S)
                    {
                        pos.remove(prv)
                    }
                    else break;
                }
                pos.add(r)
                if (ans<S) ans = S
                continue
            }
            L = pos.floor(r)
            S += res[L]
            res[r] = S
            while (true)
            {
                var prv = pos.ceiling(r)
                if (prv==null) break;
                if (res[prv]<=S)
                {
                    pos.remove(prv)
                }
                else break;
            }
            pos.add(r)
            if (ans<S) ans = S
            continue
        }
        println(ans)
    }
}