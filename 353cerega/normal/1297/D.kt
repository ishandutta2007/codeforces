fun main(args: Array<String>) = with(java.util.Scanner(System.`in`))
{
    //var n = nextInt()
    //var map: MutableMap<Int, Int>
    //var numbers: Array<Array<Int>> = Array(3, { Array(5, {0}) })
    //var numbers3: MutableSet<Int> = sortedSetOf(15, 16, 17)
    var t = nextInt()
    for (q in 1..t)
    {
        var n = nextInt()
        var k = nextInt()
        var w:Pair<Int,Int> = Pair(0,0)
        var kek = Array(n,{w})
        var keks = Array(n,{0})
        for (i in 0..(n-1))
        {
            var a = nextInt()
            kek[i] = Pair(a,i)
            keks[i] = a
        }
        kek.sortBy{cat->cat.first}
        var add = Array(n,{0})
        for (i in 0..(n-1))
        {
            if (k<0) continue
            var razn: Int
            if (i<n-1)
            {
                razn = kek[i+1].first - kek[i].first - 1
            }
            else
            {
                razn = 1000000000
            }
            if (k/(i+1)<razn)
            {
                razn = k/(i+1) + 1
                k -= razn*(i+1)
            }
            else
            {
                k-=razn*(i+1)
            }
            add[i] = razn
        }
        var pos = n-1
        var sum = 0
        while (pos>=0)
        {
            sum += add[pos]
            var a = kek[pos].first
            var b = kek[pos].second
            a += sum
            kek[pos] = Pair(a,b)
            pos--
        }
        pos = 0
        while (k<0)
        {
            k++
            var a = kek[pos].first
            var b = kek[pos].second
            a--
            kek[pos] = Pair(a,b)
            pos++
        }
        var ans = Array(n,{0})
        for (i in 0..(n-1))
        {
            ans[kek[i].second] += kek[i].first
            ans[i] -= keks[i]
        }
        for (i in 0..(n-1))
        {
            print("${ans[i]} ");
        }
        println()
    }
}