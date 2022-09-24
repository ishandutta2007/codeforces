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
        var mas = Array<Int>(n,{0})
        var pos = -1
        var m = 100000
        var sum = 0
        for (i in 0..(n-1))
        {
            var a = nextInt()
            if (a>0)
            {
                mas[i] = 1
                sum += a
                if (m>a)
                {
                    m = a
                    pos = i
                }
            }
            if (a<0)
            {
                a = -a
                if (m>a)
                {
                    m = a
                    pos = i
                }
            }
        }
        mas[pos] = 1-mas[pos]
        println(sum-m)
        for (i in 0..(n-1))
        {
            print(mas[i])
        }
        println()

    }
}