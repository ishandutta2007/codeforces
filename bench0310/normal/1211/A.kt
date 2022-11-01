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
    var n=readInt()
    var a=readInts()
    var v=mutableListOf<Pair<Int,Int>>()
    for(i in 0..n-1) v.add(Pair(a[i],i))
    v.sortBy{it.first}
    var b=mutableListOf<Int>()
    for(i in 0..n-1) if((i==0||v[i].first!=v[i-1].first)&&b.size<3) b.add(v[i].second+1)
    if(b.size<3) b=mutableListOf(-1,-1,-1)
    for(c in b) print("$c ")
    print("\n")
}