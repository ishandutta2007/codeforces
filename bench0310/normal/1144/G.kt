import java.util.*

private fun readLn()=readLine()!!
private fun readInt()=readLn().toInt()
private fun readLong()=readLn().toLong()
private fun readStrings()=readLn().split(" ").toMutableList()
private fun readInts()=readStrings().map {it.toInt()}.toMutableList()
private fun readLongs()=readStrings().map {it.toLong()}.toMutableList()

fun main()
{
    var n=readInt()
    var a=(mutableListOf(0)+readInts()).toMutableList()
    val inf=(1 shl 30)
    var dp=MutableList(n+1,{mutableListOf(-inf,inf)})
    var p=MutableList(n+1,{mutableListOf(-1,-1)})
    dp[1]=mutableListOf(inf,-inf)
    p[1]=mutableListOf(0,0)
    fun upd(i:Int,x:Int,now:Int,nxt:Int)
    {
        if((nxt==0&&x>dp[i][0])||(nxt==1&&x<dp[i][1]))
        {
            dp[i][nxt]=x
            p[i][nxt]=now
        }
    }
    for(i in 1..n-1)
    {
        if(p[i][0]!=-1)
        {
            if(a[i]<a[i+1]) upd(i+1,dp[i][0],0,0)
            if(dp[i][0]>a[i+1]) upd(i+1,a[i],0,1)
        }
        if(p[i][1]!=-1)
        {
            if(dp[i][1]<a[i+1]) upd(i+1,a[i],1,0)
            if(a[i]>a[i+1]) upd(i+1,dp[i][1],1,1)
        }
    }
    if(p[n][0]!=-1||p[n][1]!=-1)
    {
        var t=(if(p[n][0]!=-1) 0 else 1)
        var res=MutableList(n+1,{0})
        for(i in n downTo 1)
        {
            res[i]=t
            t=p[i][t]
        }
        print("YES\n")
        for(i in 1..n) print("${res[i]} ")
        print("\n")
    }
    else print("NO\n")
}