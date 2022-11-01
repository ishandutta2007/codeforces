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
    var (n,k)=readInts()
    var tmp="0"+readLn()
    var ini=MutableList(n+1,{if(tmp[it]=='1') 1 else 0})
    var switches=MutableList(n+1,{mutableListOf<Int>()})
    for(i in 1..k)
    {
        var cnt=readInt()
        for(a in readInts()) switches[a].add(i)
    }
//    println(switches)
    var p=MutableList(k+1,{it})
    var set=MutableList(k+1,{mutableListOf(it)})
    var sz=MutableList(k+1,{1})
    var c=MutableList(k+1,{0})
    var now=MutableList(k+1,{0})
    var fixed=MutableList(k+1,{false})
    var inv=MutableList(k+1,{0})
    var res=0
    fun find_set(a:Int):Int
    {
        if(a==p[a]) return a
        else
        {
            p[a]=find_set(p[a])
            return p[a]
        }
    }
    fun ch(a:Int)
    {
        for(x in set[a]) c[x]=(c[x] xor 1)
        res+=(sz[a]-2*now[a])
        now[a]=(sz[a]-now[a])
    }
    fun invert(a:Int)
    {
        res+=(sz[a]-2*now[a])
        now[a]=(sz[a]-now[a])
        inv[a]=(inv[a] xor 1)
    }
    fun merge_sets(na:Int,nb:Int,t:Int)
    {
//        println("merge $na $nb, col=$t")
        var a=find_set(na)
        var b=find_set(nb)
//        println("sets are $a $b")
//        println(set[a])
//        println(set[b])
        if(a==b) return
        var ta=na
        var tb=nb
        if(sz[a]<sz[b])
        {
            a=b.also{b=a}
            ta=tb.also{tb=ta}
        }
//        debug@ fun state(msg:String,z:Int)
//        {
//            print(msg)
//            print(" inv=${inv[z]} fixed=${fixed[z]} now=${now[z]}")
//            for(i in set[z]) print(" [$i:${c[i]}]")
//            println()
//            println()
//        }
//        state("inia",a)
//        state("inib",b)
        p[b]=a
        var otb=(c[tb] xor inv[b])
        if(inv[a]!=inv[b])
        {
//            println("invs don't match, so flip b, and set inv^=1")
            for(x in set[b]) c[x]=(c[x] xor 1)
            inv[b]=(inv[b] xor 0)
//            state("stateb:",b)
        }
        if((c[ta] xor c[tb])!=t)
        {
//            println("colors don't match t, so ch(b)")
            ch(b)
//            state("stateb:",b)
        }
        sz[a]+=sz[b]
        now[a]+=now[b]
        for(x in set[b]) set[a].add(x)
        if(fixed[b]&&(c[tb] xor inv[a])!=otb)
        {
//            println("b was fixed, and incorrect, so invert(a)")
            invert(a)
//            state("statea:",a)
        }
        if(fixed[b]) fixed[a]=true
        if(fixed[a]==false&&fixed[b]==false&&sz[a]-now[a]<now[a])
        {
//            println("neither was fixed, and better res is possible, so invert(a)")
            invert(a)
//            state("statea:",a)
        }
    }
    fun fix(ta:Int,col:Int)
    {
//        println("fix ${ta} to ${col}")
        var a=find_set(ta)
        if(fixed[a]) return
        fixed[a]=true
        if((c[ta] xor inv[a])!=col) invert(a)
    }
    for(i in 1..n)
    {
        if(switches[i].size==1) fix(switches[i][0],ini[i] xor 1)
        else if(switches[i].size==2) merge_sets(switches[i][0],switches[i][1],ini[i] xor 1)
        print("${res}\n")
    }
}