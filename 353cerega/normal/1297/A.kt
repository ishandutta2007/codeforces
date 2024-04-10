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
        if (n<1000)
        {
            println(n)
            continue
        }
        var k = n/1000
        if (n%1000>=500)
        {
            k++
        }
        if (k<1000)
        {
            println("${k}K")
            continue
        }
        k = n/1000000
        if (n%1000000>=500000)
        {
            k++
        }
        println("${k}M")
    }
}