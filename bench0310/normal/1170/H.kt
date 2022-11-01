import kotlin.math.*
private fun readLn()=readLine()!!
private fun readInt()=readLn().toInt()
private fun readLong()=readLn().toLong()
private fun readStrings()=readLn().split(" ")
private fun readInts()=readStrings().map{it.toInt()}.toMutableList()
private fun readLongs()=readStrings().map{it.toLong()}.toMutableList()

private fun solve(a:MutableList<Int>):MutableList<Int>
{
    var n=a.size
    var c=0
    var best=Pair(0,-1)
    var cnt=0
    for(i in 0..n-1)
    {
        if(i==0||a[i]!=a[i-1])
        {
            c=1
            cnt=0
            for(j in i..n-1)
            {
                if(a[j]!=a[i]) break
                cnt++
            }
        }
        else c++
        var lefteq=cnt-c
        var left=n-1-i-lefteq
        var now=min(i+1-c,lefteq)
        now=min(i+1+1,now+left)
        if(now>=i+1)
        {
            if(i+1+now>best.first) best=Pair(i+1+now,i)
        }
    }
    if(best.second==-1) return MutableList<Int>(1,{a[0]})
    cnt=0
    for(b in a) if(b==a[best.second]) cnt++
    c=0
    for(i in 0..best.second) if(a[i]==a[best.second]) c++
    var rest=best.second
    while(rest<n&&a[rest]==a[best.second]) rest++
    var res=MutableList<Int>(best.first,{0})
    for(i in 0..best.second) res[2*i+1]=a[i]
    var idx=0
    fun go(x:Int):Unit
    {
        res[idx]=x
        idx+=2
    }
    var lefteq=cnt-c
    var now=min(best.second+1-c,lefteq)
    for(i in 0..now-1) go(a[best.second])
    for(i in 0..best.first-(best.second+1)-now-1) go(a[rest+i])
    return res
}

fun main()
{
    var t=readInt()
    while((t--)>0)
    {
        var n=readInt()
        var a=readInts()
        a.sort()
        var one=solve(a);
        a.reverse()
        var two=solve(a)
        if(one.size<two.size) one=two
        print("${one.size}\n")
        for(b in one) print("$b ")
        print("\n")
    }
}