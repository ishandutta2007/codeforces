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
        var n=readInt()
        var v=mutableListOf<Pair<Int,Int>>()
        for(i in 1..n)
        {
            var (a,b)=readInts()
            v.add(Pair(a,1))
            v.add(Pair(b+1,-1))
        }
        var res=-1
        v.sortBy{it.first}
        var l=0
        var now=0
        while(l<2*n)
        {
            var r=l
            while(r+1<2*n&&v[r+1].first==v[l].first) r++
            for(i in l..r) now+=v[i].second
            if(now==1) res=v[l].first
            l=r+1
        }
        print("$res\n")
    }
}