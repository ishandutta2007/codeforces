import java.util.*

fun main()
{
    val m:Int=readLine()!!.toInt()
    val a=readLine()!!.split(" ").map{it->it.toInt()}
    var n:Int=0
    for(i in 0..m-1)
    {
        if(a[i]==-1) n++
    }
    var id=TreeSet<Int>()
    for(i in 0..n-1)
    {
        id.add(i)
    }
    var res=List(n,{MutableList<Int>(0){0}})
    var now:Int=0
    while(now<m)
    {
        var v= MutableList<Int>(0){0}
        for(i in id)
        {
            if(a[now]==-1)
            {
                v.add(i)
            }
            else
            {
                res[i].add(a[now])
            }
            now++
        }
        for(i in v)
        {
            id.remove(i)
        }
    }
    println(n)
    for(i in 0..n-1)
    {
        print("${res[i].size} ")
        println(res[i].joinToString(" "))
    }
}