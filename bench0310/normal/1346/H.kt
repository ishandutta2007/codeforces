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
    var (n,m)=readInts()
    var queries=mutableListOf<Pair<Int,Int>>()
    for(i in 0..n-1)
    {
        var (a,b)=readInts()
        queries.add(Pair(a,b))
    }
    val N=2000000
    var v=MutableList(N+3,{TreeSet<Int>()})
    for(i in 0..m-1)
    {
        var (a,b)=readInts()
        v[a+b].add(b-a)
    }
    for((l,r) in queries)
    {
        var res=N
        var one=v[l+r].floor(r-l)
        if(one!=null) res=min(res,(-l+r-one)/2)
        var two=v[l+r+2].floor(r-l-2)
        var three=v[l+r-2].floor(r-l-2)
        if(two!=null&&three!=null) res=min(res,max(-l+r-two,-l+r-three)/2)
        if(res==N) res=-1
        print("$res ")
    }
    print("\n")
}