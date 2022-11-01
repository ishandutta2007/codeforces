import kotlin.math.min
import kotlin.math.max
import java.util.*

private fun readLn()=readLine()!!
private fun readInt()=readLn().toInt()
private fun readLong()=readLn().toLong()
private fun readStrings()=readLn().split(" ")
private fun readInts()=readStrings().map {it.toInt()}.toMutableList()
private fun readLongs()=readStrings().map {it.toLong()}.toMutableList()

private val N=200005
private var v=MutableList(N,{mutableListOf<Int>()})
private var g=MutableList(N,{mutableListOf<Int>()})
private var p=MutableList(N,{0})
private var depth=MutableList(N,{0})
private var tin=MutableList(N,{0})
private var tcnt=1
private var inc=MutableList(N,{false})
private var path=mutableListOf<Int>()

private fun dfs(a:Int):Unit
{
    depth[a]=depth[p[a]]+1
    tin[a]=tcnt++
    for(to in v[a])
    {
        if(to==p[a]) continue
        p[to]=a
        dfs(to)
    }
}

private fun lca(x:Int,y:Int):Int
{
    var a=x
    var b=y
    while(depth[a]>depth[b]) a=p[a]
    while(depth[b]>depth[a]) b=p[b]
    if(a==b) return a
    while(p[a]!=p[b])
    {
        a=p[a]
        b=p[b]
    }
    return p[a]
}

private fun go(a:Int,par:Int):Unit
{
    path.add(a)
    for(to in g[a]) if(to!=par) go(to,a)
}

fun main()
{
    var t=readInt()
    while((t--)>0)
    {
        var n=readInt()
        var c=mutableListOf<Int>(0)+readInts()
        var d=mutableListOf<Int>(0)+readInts()
        var edges=MutableList(n-1,{Pair(0,0)})
        for(i in 0..n-2)
        {
            var (a,b)=readInts()
            v[a].add(b)
            v[b].add(a)
            edges[i]=Pair(a,b)
        }
        dfs(1)
        var bad=mutableListOf<Int>()
        for(i in 1..n) if(c[i]!=d[i]) bad.add(i)
        bad.sortBy{tin[it]}
        if(bad.isEmpty()) print("Yes\n0\n")
        else if(bad.size==1) print("No\n")
        else
        {
            inc[lca(bad[0],bad.last())]=true
            for(b in bad)
            {
                var c=b
                while(inc[c]==false)
                {
                    inc[c]=true
                    c=p[c]
                }
            }
            bad.clear()
            for(i in 1..n) if(inc[i]==true) bad.add(i)
            for((a,b) in edges)
            {
                if(inc[a]==true&&inc[b]==true)
                {
                    g[a].add(b)
                    g[b].add(a)
                }
            }
            var ok=true
            var endpoints=mutableListOf<Int>()
            for(a in bad)
            {
                if(g[a].size==1) endpoints.add(a)
                else if(g[a].size>=3) ok=false
            }
            if(ok==false||endpoints.size!=2) print("No\n")
            else
            {
                fun ch():MutableList<Int>?
                {
                    var sz=path.size
                    for(i in 0..sz-1) if(c[path[(i+1)%sz]]!=d[path[i]]) return null
                    return path
                }
                go(endpoints[0],0)
                var res=ch()
                if(res==null)
                {
                    path.reverse()
                    res=ch()
                }
                if(res==null) print("No\n")
                else
                {
                    print("Yes\n")
                    print("${res.size}\n")
                    for(a in res) print("$a ")
                    print("\n")
                }
            }
        }
        //spring cleaning
        for(i in 1..n)
        {
            v[i].clear()
            g[i].clear()
            p[i]=0
            depth[i]=0
            tin[i]=0
            inc[i]=false
        }
        tcnt=1
        path.clear()
    }
}