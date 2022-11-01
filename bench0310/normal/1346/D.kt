import kotlin.math.min
import kotlin.math.max
import java.util.*

private fun readLn()=readLine()!!
private fun readInt()=readLn().toInt()
private fun readLong()=readLn().toLong()
private fun readStrings()=readLn().split(" ")
private fun readInts()=readStrings().map {it.toInt()}.toMutableList()
private fun readLongs()=readStrings().map {it.toLong()}.toMutableList()

fun main()
{
    var t=readInt()
    while((t--)>0)
    {
        var (n,m)=readInts()
        var x=MutableList(n+1,{0})
        var edges=MutableList(m,{Triple(0,0,0)})
        for(i in 0..m-1)
        {
            var (a,b,c)=readInts()
            x[a]=max(x[a],c)
            x[b]=max(x[b],c)
            edges[i]=Triple(a,b,c)
        }
        var ok=true
        for((a,b,c) in edges) if(min(x[a],x[b])!=c) ok=false
        if(ok)
        {
            print("YES\n")
            for(i in 1..n) print("${x[i]} ")
            print("\n")
        }
        else print("NO\n")
    }
}