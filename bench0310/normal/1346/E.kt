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
    var (n,m,k)=readInts()
    val inf=m+1
    var d=MutableList(n+1,{inf})
    d[k]=0
    while((m--)>0)
    {
        var (a,b)=readInts()
        var da=d[a]
        var db=d[b]
        d[a]=min(da+1,db)
        d[b]=min(db+1,da)
    }
    for(i in 1..n) print("${if(d[i]!=inf) d[i] else -1} ")
    print("\n")
}