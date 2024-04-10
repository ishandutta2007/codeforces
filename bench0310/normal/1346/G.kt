import kotlin.math.min
import kotlin.math.max
import java.util.*

private fun readLn()=readLine()!!
private fun readInt()=readLn().toInt()
private fun readLong()=readLn().toLong()
private fun readStrings()=readLn().split(" ")
private fun readInts()=readStrings().map {it.toInt()}.toMutableList()
private fun readLongs()=readStrings().map {it.toLong()}.toMutableList()

private tailrec fun gcd(a:Int,b:Int):Int
{
    if(b==0) return a
    else return gcd(b,a%b)
}

fun main()
{
    var (k,n)=readInts()
    var cameras=TreeSet<Int>()
    var tmp=readInts()
    for(a in tmp) cameras.add(a)
    var points=readInts()
    var res=mutableListOf<Int>()
    val N=1000000
    var div=MutableList(N+1,{0})
    for(c in cameras)
    {
        for(i in c..N step c) div[i]=c
    }
    fun solve(x:Int,mv:Int):Unit
    {
        if(cameras.contains(mv)==false) return
        var now=mutableListOf<Int>()
        for(a in points) if(a<x||((a-x)%mv)!=0) now.add(a)
        if(now.size==0) now.add(1)
        if(now.size==1) now.add(now[0]+cameras.first())
        var g=now[1]-now[0]
        for(i in 0..now.size-2) g=gcd(g,now[i+1]-now[i])
        if(div[g]==0) return
        res=mutableListOf(x,mv,now[0],div[g])
    }
    fun divisors(a:Int):MutableList<Int>
    {
        var d=mutableListOf<Int>()
        for(i in 1..a)
        {
            if(i*i>a) break
            if((a%i)!=0) continue
            d.add(i)
            if(i*i<a) d.add(a/i)
        }
        return d
    }
    solve(points[0],cameras.first())
    for(d in divisors(points.last()-points[0])) solve(points[0],d)
    if(n>=3)
    {
        for(d in divisors(points[1]-points[0])) solve(points[0],d)
        for(d in divisors(points.last()-points[1])) solve(points[1],d)
    }
    if(res.size==4) print("YES\n${res[0]} ${res[1]}\n${res[2]} ${res[3]}\n")
    else print("NO\n")
}