import kotlin.math.min
import kotlin.math.max
import java.util.*
import kotlin.system.exitProcess

private fun readLn()=readLine()!!
private fun readInt()=readLn().toInt()
private fun readLong()=readLn().toLong()
private fun readStrings()=readLn().split(" ")
private fun readInts()=readStrings().map {it.toInt()}.toMutableList()
private fun readLongs()=readStrings().map {it.toLong()}.toMutableList()

fun main()
{
    var (n,k)=readInts()
    var v=MutableList<Triple<Int,Int,Int>>(n,{Triple(0,0,0)})
    var one:Long=0
    var two:Long=0
    for(i in 0..n-1)
    {
        var (a,b,c)=readInts()
        v[i]=Triple(a,b,c)
        one+=a
        two+=b
    }
    if(!(one<=k&&k<=two))
    {
        print("-1\n")
        exitProcess(0)
    }
    v.sortBy{it.third}
    var res:Long=0
    for((a,b,c) in v)
    {
        one-=a
        var now=min(k-one,b.toLong())
        res+=(now*c)
        k-=now.toInt()
    }
    print("${res}\n")
}