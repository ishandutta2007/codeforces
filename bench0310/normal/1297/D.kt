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
        var (n,k)=readInts()
        var z=readInts()
        var a=MutableList(n,{Pair(0,0)})
        for(i in 0..n-1) a[i]=Pair(z[i],i)
        a.sortBy{it.first}
        var l=a.last().first-1
        var r=a.last().first+k
        while(l<r-1)
        {
            var m=((l.toLong()+r)/2).toInt()
            var c:Long=0
            for(i in 0..n-1) c+=(m-i-a[n-1-i].first)
            if(c>=k.toLong()) r=m
            else l=m
        }
        var res=MutableList(n,{0})
        for(i in 0..n-1)
        {
            res[a[n-1-i].second]=min(k,r-i-a[n-1-i].first)
            k-=res[a[n-1-i].second]
        }
        for(i in 0..n-1) print("${res[i]} ")
        print("\n")
    }
}