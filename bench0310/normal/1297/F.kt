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
        var (n,m)=readInts()
        var movies=TreeMap<Int,MutableList<Pair<Int,Int>>>()
        for(i in 1..n)
        {
            var (a,b)=readInts()
            if(movies.containsKey(a)==false) movies.put(a,mutableListOf<Pair<Int,Int>>())
            movies[a]!!.add(Pair(b,i))
        }
        var res=MutableList(n+1,{0})
        var cmp=compareBy<Pair<Int,Int>>({it.first},{it.second})
        var s=TreeSet<Pair<Int,Int>>(cmp)
        var d=0
        var i=1
        while(true)
        {
            if(movies.containsKey(i))
            {
                for(p in movies[i]!!) s.add(p)
            }
            for(j in 1..m)
            {
                if(s.isEmpty()) break
                var p=s.first()
                s.remove(p)
                res[p.second]=i
                d=max(d,i-p.first)
            }
            if(s.isEmpty())
            {
                if(movies.higherKey(i)==null) break
                else i=movies.higherKey(i)
            }
            else i++
        }
        print("$d\n")
        for(j in 1..n) print("${res[j]} ")
        print("\n")
    }
}