fun main()
{
    val t:Int=readLine()!!.toInt()
    var x:Int
    for(i in 1..t)
    {
        x=readLine()!!.toInt()
        var res:Int=0
        if(x%2==1)
        {
            res++
            x-=3
        }
        res+=x/2
        println(res)
    }
}