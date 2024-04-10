import kotlin.math.min
import kotlin.math.max
import kotlin.math.abs
import java.util.*

private fun readLn()=readLine()!!
private fun readInt()=readLn().toInt()
private fun readLong()=readLn().toLong()
private fun readStrings()=readLn().split(" ")
private fun readInts()=readStrings().map {it.toInt()}.toMutableList()
private fun readLongs()=readStrings().map {it.toLong()}.toMutableList()

fun main()
{
    var v=mutableListOf<Pair<Int,String>>()
    for(i in 0..999) v.add(Pair(i,i.toString()))
    for(i in 1..999) v.add(Pair(1000*i,i.toString()+"K"))
    for(i in 1..2000) v.add(Pair(1000000*i,i.toString()+"M"))
    var t=readInt()
    while((t--)>0)
    {
        var n=readInt()
        for(i in 0..v.size-2)
        {
            if(v[i].first<=n&&n<=v[i+1].first)
            {
                var a=(n-v[i].first)
                var b=(v[i+1].first-n)
                if(a<b) print("${v[i].second}\n")
                else print("${v[i+1].second}\n")
                break
            }
        }
    }
}