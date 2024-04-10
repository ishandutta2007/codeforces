fun main()
{
    val t=readLine()!!.toInt()
    repeat(t)
    {
        var(a,b)=readLine()!!.split(" ").map{it->it.toInt()}
        if(a>b) a=b.also{b=a}
        println("1 ${a-1} ${b-a+1}")
    }
}