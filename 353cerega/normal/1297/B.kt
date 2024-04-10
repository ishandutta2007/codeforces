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
        var w:Pair<Int,Int> = Pair(0,0)
        var numbers = Array(n,{w})

        for (i in 0..(n-1))
        {
            var a = nextInt()
            var b = nextInt()
            numbers[i] = Pair(a,b)
        }
        numbers.sortBy { cat -> cat.first }
        var ok = 0
        var l = numbers[0].first
        var r = numbers[0].second
        for (i in 1..(n-1))
        {
            if (r==-1)
            {
                if (numbers[i].second<l)
                {
                    continue
                }
                if (l<numbers[i].first)
                {
                    l = numbers[i].first
                }
                r = numbers[i].second
                continue
            }
            if (l>numbers[i].second)
            {
                continue
            }
            if (l<numbers[i].first)
            {
                println(l)
                ok = 1
                break
            }
            if (numbers[i].second>r)
            {
                l = r+1
                r = numbers[i].second
                continue
            }
            if (numbers[i].second==r)
            {
                l = r+1
                r = -1
                continue
            }
            if (numbers[i].second<r)
            {
                l = numbers[i].second+1
            }
        }
        if (ok==0)
        {
            if (r!=-1)
            {
                println(r)
                continue
            }
            println(-1)
        }
    }
}