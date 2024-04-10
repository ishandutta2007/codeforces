import kotlin.math.min
import kotlin.math.max
import java.util.*
import kotlin.collections.ArrayList
import kotlin.system.exitProcess

private fun readLn()=readLine()!!
private fun readInt()=readLn().toInt()
private fun readLong()=readLn().toLong()
private fun readStrings()=readLn().split(" ")
private fun readInts()=readStrings().map {it.toInt()}.toMutableList()
private fun readLongs()=readStrings().map {it.toLong()}.toMutableList()

fun main()
{
    var (m,num)=readInts()
    var t=m
    while((t%2)==0) t/=2
    while((t%3)==0) t/=3
    while((t%5)==0) t/=5
    while((t%7)==0) t/=7
    if(t>1)
    {
        print("-1\n")
        exitProcess(0)
    }
    if(m==2||m==3||m==5||m==7)
    {
        var len=1
        while(true)
        {
            if(num>len)
            {
                num-=len
                len++
            }
            else break
        }
        var pos=len-num+1
        for(i in 1..pos-1) print("1")
        print("$m")
        for(i in pos+1..len) print("1")
        print("\n")
        exitProcess(0)
    }
    val lim=1000000000
    if(m<=100)
    {
        val n=2000
        var dp=MutableList(n+1,{MutableList(m+1,{0})})
        dp[0][1]=1
        for(i in 0..n-1)
        {
            for(j in 1..m)
            {
                if(dp[i][j]==0) continue
                for(a in 1..9)
                {
                    if(a*j>m) break
                    dp[i+1][a*j]=min(dp[i+1][a*j]+dp[i][j],lim)
                }
            }
        }
        var len=1
        while(num>dp[len][m])
        {
            num-=dp[len][m]
            len++
        }
        for(i in len downTo 1)
        {
            for(j in 1..9)
            {
                if((m%j)!=0) continue
                if(dp[i-1][m/j]>=num)
                {
                    print("$j")
                    m/=j
                    break
                }
                else num-=dp[i-1][m/j]
            }
        }
        print("\n")
        exitProcess(0)
    }
    var f=mutableListOf<Int>()
    var h=HashMap<Int,Int>()
    for(a in 0..29)
    {
        for(b in 0..18)
        {
            for(c in 0..12)
            {
                for(d in 0..10)
                {
                    var now:Long=1
                    fun mul(x:Int,e:Int):Unit
                    {
                        for(i in 1..e)
                        {
                            if(now>lim) break
                            now*=x
                        }
                    }
                    mul(2,a)
                    mul(3,b)
                    mul(5,c)
                    mul(7,d)
                    if(now>lim) continue
                    var idx=f.size
                    f.add(now.toInt())
                    h.put(now.toInt(),idx)
                }
            }
        }
    }
    val n=500
    val k=f.size
    var dp=MutableList(n+1,{MutableList(k,{0})})
    var pre=MutableList(k,{MutableList(10,{-1})})
    for(j in 0..k-1)
    {
        for(a in 1..9)
        {
            var p=f[j]
            if(a>(lim/p)) break
            pre[j][a]=h[a*p]!!
        }
    }
    dp[0][h[1]!!]=1
    for(i in 0..n-1)
    {
        for(j in 0..k-1)
        {
            if(dp[i][j]==0) continue
            for(a in 1..9)
            {
                if(pre[j][a]==-1) break
                dp[i+1][pre[j][a]]=min(dp[i+1][pre[j][a]]+dp[i][j],lim)
            }
        }
    }
    var len=1
    while(num>dp[len][h[m]!!])
    {
        num-=dp[len][h[m]!!]
        len++
    }
    for(i in len downTo 1)
    {
        for(j in 1..9)
        {
            if((m%j)!=0) continue
            if(dp[i-1][h[m/j]!!]>=num)
            {
                print("$j")
                m/=j
                break
            }
            else num-=dp[i-1][h[m/j]!!]
        }
    }
    print("\n")
}