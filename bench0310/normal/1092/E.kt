import java.util.*

private fun readLn()=readLine()!!
private fun readInt()=readLn().toInt()
private fun readLong()=readLn().toLong()
private fun readStrings()=readLn().split(" ").toMutableList()
private fun readInts()=readStrings().map {it.toInt()}.toMutableList()
private fun readLongs()=readStrings().map {it.toLong()}.toMutableList()

fun main()
{
    var (n,m)=readInts()
    var v=MutableList(n+1,{mutableListOf<Int>()})
    for(i in 1..m)
    {
        var (a,b)=readInts()
        v[a].add(b)
        v[b].add(a)
    }
    var d=MutableList(n+1,{-1})
    var p=MutableList(n+1,{-1})
    var vis=MutableList(n+1,{false})
    fun bfs(src:Int,clean:Boolean):Triple<Int,Int,Int> //last,mid,dist
    {
        var q=mutableListOf(src)
        var idx=0
        d[src]=1
        p[src]=0
        var r=src
        while(idx<q.size)
        {
            r=q[idx++]
            for(to in v[r])
            {
                if(d[to]==-1)
                {
                    d[to]=d[r]+1
                    p[to]=r
                    q.add(to)
                }
            }
        }
        var m=r
        for(i in 1..d[r]/2) m=p[m]
        var dist=d[r]
        if(clean)
        {
            for(a in q)
            {
                d[a]=-1
                p[a]=-1
            }
        }
        return Triple(r,m,dist)
    }
    fun go(src:Int):Pair<Int,Int> //center,diameter
    {
        var t=bfs(src,true).first
        var (a,m,diam)=bfs(t,false)
        return Pair(m,diam)
    }
    var e=mutableListOf<Pair<Int,Int>>()
    for(i in 1..n) if(d[i]==-1) e.add(go(i))
    e.sortByDescending{it.second}
    var diam=e[0].second
    for(i in 1..e.size-1) diam=maxOf(diam,(diam+2)/2+(e[i].second+2)/2)
    print("${diam-1}\n")
    for(i in 1..e.size-1) print("${e[0].first} ${e[i].first}\n")
}