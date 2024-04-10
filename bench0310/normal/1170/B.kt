fun main()
{
    val n=readLine()!!.toInt()
    val a=readLine()!!.split(" ").map{it->it.toInt()}
    var res:Int=0
    if(n>=3)
    {
        var one=a[0]
        var two=a[1]
        if(one<two) one=two.also{two=one}
        for(i in 2..(n-1))
        {
            if((one>a[i])&&(two>a[i])) res++
            if(a[i]>one)
            {
                two=one
                one=a[i]
            }
            else if(a[i]>two)
            {
                two=a[i]
            }
        }
        println("$res")
    }
    else
    {
        println("0")
    }
}