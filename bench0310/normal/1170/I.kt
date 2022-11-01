import kotlin.math.*
import java.util.*

private fun readLn()=readLine()!!
private fun readInt()=readLn().toInt()
private fun readLong()=readLn().toLong()
private fun readStrings()=readLn().split(" ")
private fun readInts()=readStrings().map{it.toInt()}.toMutableList()
private fun readLongs()=readStrings().map{it.toLong()}.toMutableList()

private val N=200005
private var tree=MutableList<Int>(4*(4*N),{0})
private var lazy=MutableList<Int>(4*(4*N),{1})
private val mod=998244353

private fun push(idx:Int):Unit
{
    for(i in 0..1)
    {
        tree[2*idx+i]=((lazy[idx].toLong()*tree[2*idx+i])%mod).toInt()
        lazy[2*idx+i]=((lazy[idx].toLong()*lazy[2*idx+i])%mod).toInt()
    }
    lazy[idx]=1
}

private fun update(idx:Int,l:Int,r:Int,pos:Int,x:Int):Unit
{
    if(l==r) tree[idx]=(tree[idx]+x)%mod
    else
    {
        var m=(l+r)/2
        push(idx)
        if(pos<=m) update(2*idx,l,m,pos,x)
        else update(2*idx+1,m+1,r,pos,x)
        tree[idx]=(tree[2*idx]+tree[2*idx+1])%mod
    }
}

private fun updater(idx:Int,l:Int,r:Int,ql:Int,qr:Int):Unit
{
    if(ql>qr) return;
    if(l==ql&&r==qr)
    {
        tree[idx]=(2*tree[idx])%mod
        lazy[idx]=(2*lazy[idx])%mod
    }
    else
    {
        var m=(l+r)/2
        push(idx)
        updater(2*idx,l,m,ql,min(qr,m))
        updater(2*idx+1,m+1,r,max(ql,m+1),qr)
        tree[idx]=(tree[2*idx]+tree[2*idx+1])%mod
    }
}

private fun query(idx:Int,l:Int,r:Int,ql:Int,qr:Int):Int
{
    if(ql>qr) return 0
    if(l==ql&&r==qr) return tree[idx]
    var m=(l+r)/2
    push(idx)
    return (query(2*idx,l,m,ql,min(qr,m))+query(2*idx+1,m+1,r,max(ql,m+1),qr))%mod
}

fun main()
{
    var n=readInt()
    var v= MutableList<Pair<Int,Int>>(n,{Pair(0,0)})
    var s=TreeSet<Int>()
    for(i in 0..n-1)
    {
        var (a,b)=readInts()
        a*=2
        b*=2
        v[i]=Pair(a,b)
        for(j in a-1..a) s.add(j)
        for(j in b-1..b) s.add(j)
    }
    var m=TreeMap<Int,Int>()
    var idx=1
    for(a in s) m[a]=idx++
    for(i in 0..n-1) v[i]=Pair(m[v[i].first]!!,m[v[i].second]!!)
    v.sortBy{it.first}
    var res:Long=1
    var l=0
    while(l<n)
    {
        var two=v[l].second
        var r=l
        while(r<n&&v[r].first<=two)
        {
            two=max(two,v[r].second)
            r++;
        }
        var one=v[l].first
        update(1,1,4*n,one-1,1)
        for(i in l..r-1)
        {
            var (a,b)=v[i]
            updater(1,1,4*n,b,two)
            update(1,1,4*n,b,query(1,1,4*n,a-1,b-1))
        }
        res=(res*query(1,1,4*n,two,two))%mod
        l=r
    }
    print("$res\n")
}