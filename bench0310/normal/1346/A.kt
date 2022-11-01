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
        var (n,k)=readLongs()
        var l:Long=0
        var r:Long=n+1
        while(l<r-1)
        {
            var m=(l+r)/2
            if((m+k*m+k*k*m+k*k*k*m)<=n) l=m
            else r=m
        }
        print("${l} ${l*k} ${l*k*k} ${l*k*k*k}\n")
    }
}