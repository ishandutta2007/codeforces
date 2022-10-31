import java.util.*
fun main(args: Array<String>)
{
    val sc=Scanner(System.`in`)
    var t=sc.nextInt()
    for(i in 1..t)
    {
        var n=sc.nextInt()
        if(n<1000)
        {
            println(n)
            continue
        }
        if(n<999500)
        {
            print((n+500)/1000)
            println("K")
            continue
        }
        print((n+500000)/1000000)
        println("M")
    }
}