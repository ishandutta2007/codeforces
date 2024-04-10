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
        var (n,k,x,y)=readInts()
        var a=readInts()
        a.sortDescending()
        var sum:Long=0
        for(i in 0..n-1) sum+=a[i]
        var res=n*x
        for(i in 0..n-1) if(a[i]<=k) res=min(res,i*x)
        var idx=0
        var now=0
        while((sum+n-1)/n>k)
        {
            sum-=a[idx++]
            now+=x
        }
        res=min(res,now+y)
        print("$res\n")
    }
}