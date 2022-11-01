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
    var a=(mutableListOf(0L)+readLongs()).toMutableList()
    var x=readLong()
    for(i in 1..n/2) a.add(x)
    var k=n/2+1
    var sum=MutableList(n-k+1,{0L})
    for(i in 1..n-k) sum[i]=sum[i-1]+(x-a[i])
    var mn=MutableList(n-k+1,{0L})
    for(i in 1..n-k) mn[i]=min(mn[i-1],sum[i])
    var now=0L
    for(i in 1..k-1) now+=a[i]
    var res=-1
    while(k<=n)
    {
        now+=a[k]
        if(mn.last()+now>0)
        {
            res=k
            break
        }
        mn.removeLast()
        k++
    }
    println(res)
}