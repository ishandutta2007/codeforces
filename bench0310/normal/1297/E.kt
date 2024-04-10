import kotlin.math.min
import kotlin.math.max
import java.util.*

private fun readLn()=readLine()!!
private fun readInt()=readLn().toInt()
private fun readLong()=readLn().toLong()
private fun readStrings()=readLn().split(" ")
private fun readInts()=readStrings().map {it.toInt()}.toMutableList()
private fun readLongs()=readStrings().map {it.toLong()}.toMutableList()

private val N=300005
private var v=MutableList(N,{mutableListOf<Int>()})
private var depth=MutableList(N,{0})
private var p=MutableList(N,{0})
private var tin=MutableList(N,{0})
private var tcnt=1
private var x=MutableList(N,{false})

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

private fun go(a:Int):Unit
{
    var b=a
    while(b!=0&&x[b]==false)
    {
        x[b]=true
        b=p[b]
    }
}

fun main()
{
    var t=readInt()
    while((t--)>0)
    {
        var (n,k)=readInts()
        for(i in 1..n-1)
        {
            var (a,b)=readInts()
            v[a].add(b)
            v[b].add(a)
        }
        if(k==1) print("Yes\n1\n1\n")
        else if(n==2) print("Yes\n2\n1 2\n")
        else
        {
            var root=1
            for(i in 1..n) if(v[i].size>1) root=i
            dfs(root)
            var chosen=mutableListOf<Int>()
            for(i in 1..n)
            {
                if(k>0&&v[i].size==1)
                {
                    chosen.add(i)
                    k--
                }
            }
            if(k==0)
            {
                chosen.sortBy{tin[it]}
                x[lca(chosen[0],chosen.last())]=true
                for(a in chosen) go(a)
                print("Yes\n")
                var res=mutableListOf<Int>()
                for(i in 1..n) if(x[i]==true) res.add(i)
                print("${res.size}\n")
                for(a in res) print("$a ")
                print("\n")
            }
            else print("No\n")
        }
        for(i in 1..n)
        {
            v[i].clear()
            p[i]=0
            depth[i]=0
            tin[i]=0
            x[i]=false
        }
        tcnt=1
    }
}