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
        var (n,k1,k2)=readInts()
        var s=readLn()
        var res=0
        var x=0
        for(i in 0..n-1)
        {
            if(s[i]=='0') x=0
            else
            {
                x=min(k1,k2-x)
                res+=x
            }
        }
        print("$res\n")
    }
}