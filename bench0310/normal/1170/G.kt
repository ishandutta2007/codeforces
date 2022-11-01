import java.util.*
import kotlin.system.exitProcess

private fun readLn()=readLine()!!
private fun readInt()=readLn().toInt()
private fun readLong()=readLn().toLong()
private fun readStrings()=readLn().split(" ")
private fun readInts()=readStrings().map{it.toInt()}.toMutableList()
private fun readLongs()=readStrings().map{it.toLong()}.toMutableList()

val N=200005
var v=Array<TreeMap<Int,Int>>(N,{TreeMap<Int,Int>()})
var st=mutableListOf<Int>()
var vis=MutableList<Boolean>(N,{false})
var res=mutableListOf<MutableList<Int>>()

fun out()
{
    print("NO\n")
    exitProcess(0)
}

fun dfs(a:Int):Int
{
    st.add(a)
    if(vis[a]==true)
    {
        //println("cycle found: $st")
        st.removeLast()
        var cycle=mutableListOf<Int>(a)
        while(st.last()!=a)
        {
            cycle.add(st.last())
            vis[st.last()]=false
            st.removeLast()
        }
        cycle.add(a)
        res.add(cycle)
        return a
    }
    vis[a]=true
    while(true)
    {
        if(v[a].isEmpty())
        {
            if(st.size>1) out()
            else
            {
                st.removeLast()
                return 0
            }
        }
        var (to,c)=v[a].firstEntry()
        c--
        if(c==0)
        {
            v[a].remove(to)
            v[to].remove(a)
        }
        else
        {
            v[a].put(to,c)
            v[to].put(a,c)
        }
        var x=dfs(to)
        if(x==0) out()
        else if(x!=a) return x
    }
}

fun main()
{
    var (n,m)=readInts()
    for(i in 1..m)
    {
        var (a,b)=readInts()
        var c=v[a].get(b)
        if(c==null) c=0
        c++
        v[a].put(b,c)
        v[b].put(a,c)
    }
    for(i in 1..n) if(v[i].isEmpty()==false) dfs(i)
    print("YES\n")
    print("${res.size}\n")
    for(cycle in res)
    {
        print(cycle.size)
        for(c in cycle) print(" $c")
        print("\n")
    }
}