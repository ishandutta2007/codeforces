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
        var a=readInts()
        var res=MutableList(n,{'0'})
        var sum=0
        var one=Pair(10001,-1)
        var two=Pair(-10001,-1)
        for(i in 0..n-1)
        {
            if(a[i]>0)
            {
                sum+=a[i]
                res[i]='1'
                if(a[i]<one.first) one=Pair(a[i],i)
            }
            if(a[i]<0)
            {
                if(a[i]>two.first) two=Pair(a[i],i)
            }
        }
        if(two.second==-1||(one.second!=-1&&two.second!=-1&&sum-one.first>sum+two.first))
        {
            sum-=one.first
            res[one.second]='0'
        }
        else
        {
            sum+=two.first
            res[two.second]='1'
        }
        print("$sum\n")
        for(i in 0..n-1) print("${res[i]}")
        print("\n")
    }
}