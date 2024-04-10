import kotlin.math.min
import kotlin.math.max
import java.util.*

private fun readLn()=readLine()!!
private fun readInt()=readLn().toInt()
private fun readLong()=readLn().toLong()
private fun readStrings()=readLn().split(" ")
private fun readInts()=readStrings().map {it.toInt()}.toMutableList()
private fun readLongs()=readStrings().map {it.toLong()}.toMutableList()

private val N=3005
private var v=MutableList(N,{mutableListOf<Pair<Int,Int>>()})
private var best=MutableList(N,{-1})
private var h=MutableList(N,{MutableList(N,{0})})
private var res=MutableList(N,{0})
private var x=MutableList(N,{false})
private var c=0
private var cnow=2

private fun dfs(a:Int,p:Int=0):Unit
{
    best[a]=-1
    for(i in 1..c) h[a][i]=0
    var sum=0
    var up=(if(p!=0) 1 else 0)
    for((to,id) in v[a])
    {
        if(to==p) continue
        dfs(to,a)
        if(best[to]==-1) return
        for(i in c downTo best[to]) if(h[a][i]==0&&h[a][i-best[to]]!=0) h[a][i]=to
        sum+=best[to]
    }
    var mx=0
    for(i in 1..c) if(h[a][i]!=0) mx=i
    best[a]=sum-mx+up
    if(best[a]>c) best[a]=-1
}

private fun color(a:Int,p:Int=0,col:Int=1):Unit
{
    var mx=0
    for(i in 1..c) if(h[a][i]!=0) mx=i
    while(mx>0)
    {
        x[h[a][mx]]=true
        mx-=best[h[a][mx]]
    }
    var cnxt=cnow++
    for((to,id) in v[a])
    {
        if(to==p) continue
        var tmp=(if(x[to]==false) col else cnxt)
        res[id]=tmp
        color(to,a,tmp)
    }
}

fun main()
{
    var t=readInt()
    while((t--)>0)
    {
        var n=readInt()
        for(i in 1..n-1)
        {
            var (a,b)=readInts()
            v[a].add(Pair(b,i))
            v[b].add(Pair(a,i))
        }
        for(i in 1..n) h[i][0]=-1
        var l=0
        var r=n
        while(l<r-1)
        {
            var m=(l+r)/2
            c=m
            dfs(1)
            if(best[1]!=-1) r=m
            else l=m
        }
        c=r
        dfs(1)
        color(1)
        print("$r\n")
        for(i in 1..n-1) print("${res[i]} ")
        print("\n")
        for(i in 1..n)
        {
            v[i].clear()
            x[i]=false
        }
        cnow=2
    }
}