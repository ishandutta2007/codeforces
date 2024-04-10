import kotlin.math.min
import kotlin.math.max
import java.util.*
import kotlin.collections.ArrayDeque

private fun readLn()=readLine()!!
private fun readInt()=readLn().toInt()
private fun readLong()=readLn().toLong()
private fun readStrings()=readLn().split(" ")
private fun readInts()=readStrings().map {it.toInt()}.toMutableList()
private fun readLongs()=readStrings().map {it.toLong()}.toMutableList()

fun main()
{
    var (n,m,q,s)=readInts()
    s--
    var pellets=readLongs()
    var sum=pellets.sum()
    var sub=MutableList(1 shl n,{0L})
    for(i in 0..(1 shl n)-1)
    {
        for(j in 0..n-1) if((i and (1 shl j))!=0) sub[i]+=pellets[j]
    }
    var v=MutableList(n,{mutableListOf<Int>()})
    for(i in 0..m-1)
    {
        var (a,b)=readInts()
        v[a-1].add(b-1)
    }
    var queries=readLongs()
    var best=MutableList(n,{MutableList(n,{-1L})})
    var req=MutableList(n,{TreeSet<Pair<Long,Int>>(compareBy({it.first}))})
    for(src in 0..n-1)
    {
        var d=MutableList(n,{MutableList(1 shl n,{-1})})
        d[src][1 shl src]=0
        var queue=mutableListOf(Pair(src,1 shl src))
        var idx=0
        while(idx<queue.size)
        {
            var (a,mask)=queue[idx++]
            for(to in v[a])
            {
                var newmask=(mask or (1 shl to))
                if(d[to][newmask]==-1)
                {
                    d[to][newmask]=d[a][mask]+1
                    queue.add(Pair(to,newmask))
                }
            }
        }
        for(to in 0..n-1) best[src][to]=d[to][(1 shl n)-1].toLong()
        var now=mutableListOf<Pair<Long,Int>>()
        for(to in 0..n-1) for(mask in 0..(1 shl n)-1) if(d[to][mask]!=-1) now.add(Pair(sub[mask],d[to][mask]))
        now.sortBy{it.first}
        var mn=now.last().second
        for(i in now.size-1 downTo 0)
        {
            var (score,mv)=now[i]
            mn=min(mn,mv)
            if(i==0||now[i-1].first!=score) req[src].add(Pair(score,mn))
        }
    }
    fun multwo(a:MutableList<Long>,b:MutableList<MutableList<Long>>):MutableList<Long>
    {
        var c=MutableList(n,{-1L})
        for(i in 0..n-1) for(j in 0..n-1) if(a[i]!=-1L&&b[i][j]!=-1L&&(c[j]==-1L||a[i]+b[i][j]<c[j])) c[j]=a[i]+b[i][j]
        return c
    }
    fun mul(a:MutableList<MutableList<Long>>,b:MutableList<MutableList<Long>>):MutableList<MutableList<Long>>
    {
        var c=MutableList(n,{MutableList(n,{-1L})})
        for(i in 0..n-1)
        {
            for(j in 0..n-1)
            {
                for(k in 0..n-1)
                {
                    if(a[i][j]!=-1L&&b[j][k]!=-1L&&(c[i][k]==-1L||a[i][j]+b[j][k]<c[i][k]))
                    {
                        c[i][k]=a[i][j]+b[j][k]
                    }
                }
            }
        }
        return c
    }
    var pre=MutableList(50,{mutableListOf(mutableListOf<Long>())})
    pre[0]=best
    for(i in 1..49) pre[i]=mul(pre[i-1],pre[i-1])
    fun fastpow(one:MutableList<MutableList<Long>>,two:Long):MutableList<Long>
    {
        var b=one
        var e=two
        var res=MutableList(n,{-1L})
        res[s]=0
        for(i in 0..49)
        {
            if((e and (1L shl i))>0) res=multwo(res,pre[i])
        }
        return res
    }
    for(score in queries)
    {
        var entire=(score/sum)
        var left=(score%sum)
        var one=fastpow(best,entire)
        var res=(1L shl 60)
        for(a in 0..n-1)
        {
            if(one[a]==-1L) continue
            var two=req[a].ceiling(Pair(left,0))!!.second
            res=min(res,one[a]+two)
        }
        print("$res\n")
    }
}