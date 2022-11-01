import java.util.*

private fun readLn()=readLine()!!
private fun readInt()=readLn().toInt()
private fun readLong()=readLn().toLong()
private fun readStrings()=readLn().split(" ").toMutableList()
private fun readInts()=readStrings().map {it.toInt()}.toMutableList()
private fun readLongs()=readStrings().map {it.toLong()}.toMutableList()

fun main()
{
    var n=readInt()
    var x=mutableListOf(0)+readInts()
    var v=MutableList(n+1,{mutableListOf<Int>()})
    for(i in 1..n-1)
    {
        var (a,b)=readInts()
        v[a].add(b)
        v[b].add(a)
    }
    var now=0L
    var sum=MutableList(n+1,{0L})
    fun dfs(a:Int,p:Int)
    {
        sum[a]=x[a].toLong()
        for(to in v[a])
        {
            if(to==p) continue
            dfs(to,a)
            sum[a]+=sum[to]
        }
        if(a!=1) now+=sum[a]
    }
    dfs(1,0)
    var res=now
    fun go(a:Int,p:Int)
    {
        res=maxOf(res,now)
        for(to in v[a])
        {
            if(to==p) continue
            now+=(sum[1]-2*sum[to])
            go(to,a)
            now-=(sum[1]-2*sum[to])
        }
    }
    go(1,0)
    print("$res\n")
}