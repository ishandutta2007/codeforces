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
    var (n,a,b,k)=readInts()
    val N=1000000
    var c=MutableList<Int>(N+1,{0})
    var tmp=readInts()
    for(x in tmp) c[x]++
    var res=0
    if(a>=b)
    {
        for(i in 1..N)
        {
            if(i*k>N) break
            while(c[i]>=a&&c[i*k]>=b)
            {
                res++
                c[i]-=a
                c[i*k]-=b
            }
        }
    }
    else
    {
        for(i in N downTo 1)
        {
            if((i%k)!=0) continue
            while(c[i]>=b&&c[i/k]>=a)
            {
                res++
                c[i]-=b
                c[i/k]-=a
            }
        }
    }
    print("${res}\n")
}