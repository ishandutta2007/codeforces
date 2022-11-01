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
    var v=MutableList<MutableList<Int>>(200001,{mutableListOf<Int>()})
    for(i in 0..n-1) v[a[i]].add(i)
    fun solve(m:Int):MutableList<Char>?
    {
        var one=mutableListOf<Pair<Int,Int>>()
        var two=mutableListOf<Pair<Int,Int>>()
        for(i in 1..m)
        {
            if(v[i].size!=2) return null
            one.add(Pair(min(v[i][0],v[i][1]),i))
            two.add(Pair(max(v[i][0],v[i][1]),i))
        }
        one.sortBy{it.first}
        two.sortBy{it.first}
        for(i in 0..m-1) if(one[i].second!=two[i].second) return null
        var res=MutableList<Char>(n,{'B'})
        for((x,y) in one) res[x]='R'
        for((x,y) in two) res[x]='G'
        return res
    }
    var l=0
    var r=n/2+1
    while(l<r-1)
    {
        var m=(l+r)/2
        if(solve(m)!=null) l=m
        else r=m
    }
    var res=solve(l)!!
    for(c in res) print(c)
    print("\n")
}