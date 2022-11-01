import kotlin.math.min
import kotlin.math.max
import java.util.*

private fun readLn()=readLine()!!
private fun readInt()=readLn().toInt()
private fun readLong()=readLn().toLong()
private fun readStrings()=readLn().split(" ")
private fun readInts()=readStrings().map {it.toInt()}.toMutableList()
private fun readLongs()=readStrings().map {it.toLong()}.toMutableList()

private val N=100005
private var d=0
private var tree=MutableList(4*N,{0})
private var heights=MutableList(4*N,{mutableListOf<Int>(0)})
private var s=MutableList(N,{TreeSet<Pair<Int,Int>>(compareBy({it.first}))})
private var blocks=0

private fun update(idx:Int,l:Int,r:Int,ql:Int,qr:Int,h:Int,add:Boolean):Unit
{
    if(ql>qr) return
    if(l==ql&&r==qr)
    {
        if(add==true) heights[idx].add(h)
        else heights[idx].removeLast()
    }
    else
    {
        var m=(l+r)/2
        update(2*idx,l,m,ql,min(qr,m),h,add)
        update(2*idx+1,m+1,r,max(ql,m+1),qr,h,add)
    }
    if(l==r) tree[idx]=heights[idx].last()
    else tree[idx]=maxOf(tree[2*idx],tree[2*idx+1],heights[idx].last())
}

private fun query(idx:Int,l:Int,r:Int,ql:Int,qr:Int):Int
{
    if(ql>qr) return 0
    if(l==ql&&r==qr) return tree[idx]
    var m=(l+r)/2
    return maxOf(query(2*idx,l,m,ql,min(qr,m)),query(2*idx+1,m+1,r,max(ql,m+1),qr),heights[idx].last())
}

private fun attempt(h:Int,l:Int,r:Int):Boolean
{
    var one=s[h].lower(Pair(l,0))
    if(one!=null&&one.second>=l) return false
    var two=s[h].floor(Pair(r,0))
    if(two!=null&&two.second>r) return false
    while(true)
    {
        var now=s[h].ceiling(Pair(l,0))
        if(now==null||now.first>r) break
        update(1,1,d,now.first,now.second,h,false)
        s[h].remove(now)
        blocks--
    }
    return true
}

fun main()
{
    var (n,t)=readInts()
    d=t
    s[0].add(Pair(0,d+1))
    while((n--)>0)
    {
        var (l,r)=readInts()
        while(true)
        {
            var h=query(1,1,d,l,r)
            if(attempt(h,l,r)==false)
            {
                update(1,1,d,l,r,h+1,true)
                s[h+1].add(Pair(l,r))
                break
            }
        }
        blocks++
        print("$blocks\n")
    }
}