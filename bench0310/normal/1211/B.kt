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
    var mx=0
    var idx=0
    for(i in 0..n-1)
    {
        mx=max(mx,a[i])
        if(a[i]==mx) idx=i
    }
    print("${n.toLong()*(mx-1)+idx+1}\n")
}