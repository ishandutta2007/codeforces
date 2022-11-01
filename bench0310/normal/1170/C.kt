fun main()
{
    val k=readLine()!!.toInt()
    repeat(k)
    {
        val s:String=readLine()!!
        val t:String=readLine()!!
        var a:Int=0
        var b:Int=0
        val one:Int=s.length
        val two:Int=t.length
        var res:Boolean=true
        while(a<one&&b<two)
        {
            if(s[a]==t[b])
            {
                a++;
                b++;
                continue
            }
            if(s[a]=='+')
            {
                res=false
                break
            }
            if(a+1==one)
            {
                res=false
                break
            }
            if(s[a+1]=='+')
            {
                res=false
                break
            }
            a+=2
            b++
        }
        if(a!=one||b!=two)
        {
            res=false
        }
        println(if(res==true)"YES" else "NO")
    }
}