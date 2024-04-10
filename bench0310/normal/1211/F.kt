import kotlin.math.min
import kotlin.math.max
import java.util.*

private fun readLn()=readLine()!!
private fun readInt()=readLn().toInt()
private fun readLong()=readLn().toLong()
private fun readStrings()=readLn().split(" ")
private fun readInts()=readStrings().map {it.toInt()}.toMutableList()
private fun readLongs()=readStrings().map {it.toLong()}.toMutableList()

private var v=MutableList<MutableList<Int>>(6,{mutableListOf<Int>()})
private var euler=mutableListOf<Int>()

private fun dfs(a:Int):Unit
{
    while(!v[a].isEmpty())
    {
        var to=v[a].last()
        v[a].removeLast()
        dfs(to)
    }
    euler.add(a)
}

fun main()
{
    var n=readInt()
    var id=MutableList(6,{MutableList(6,{mutableListOf<Int>()})})
    var h=TreeMap<Char,Int>()
    var t="kotlin"
    for(j in 0..5) h[t[j]]=j
    for(i in 1..n)
    {
        var s=readLn()
        var a=h[s[0]]!!
        var b=(h[s.last()]!!+1)%6
        v[a].add(b)
        id[a][b].add(i)
    }
    dfs(0)
    euler.reverse()
    for(i in 0..euler.size-2)
    {
        print("${id[euler[i]][euler[i+1]].last()} ")
        id[euler[i]][euler[i+1]].removeLast()
    }
    print("\n")
}