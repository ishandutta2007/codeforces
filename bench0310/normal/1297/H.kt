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
        var s=readLn()
        var n=s.length
        var bad="|"
        var dp=MutableList(n,{MutableList(n+1,{bad})})
        dp[0][0]=s[0].toString()
        var h=MutableList(n,{MutableList(n+1,{Triple(0,0,'0')})})
        h[0][0]=Triple(-1,-1,'R')
        for(i in 1..n-1)
        {
            for(j in 0..i+1)
            {
                if(dp[i-1][j]+s[i]<dp[i][j])
                {
                    dp[i][j]=dp[i-1][j]+s[i]
                    h[i][j]=Triple(i-1,j,'R')
                }

                if(j>=1&&dp[i-1][j-1].length>j-1&&s[i]==dp[i-1][j-1][j-1]&&dp[i-1][j-1]<dp[i][j])
                {
                    dp[i][j]=dp[i-1][j-1]
                    h[i][j]=Triple(i-1,j-1,'B')
                }
            }
        }
        var res=bad
        var best=Pair(0,0)
        for(j in 0..n)
        {
            if(dp[n-1][j]<res)
            {
                res=dp[n-1][j]
                best=Pair(n-1,j)
            }
        }
        for(i in 1..n-1)
        {
            for(j in 0..i+1)
            {
                if(dp[i-1][j].length>j&&s[i]<dp[i-1][j][j])
                {
                    if(dp[i-1][j]<res)
                    {
                        res=dp[i-1][j]
                        best=Pair(i-1,j)
                    }
                }
            }
        }
        var c=MutableList(n,{'B'})
        while(best.first!=-1)
        {
            c[best.first]=h[best.first][best.second].third
            best=Pair(h[best.first][best.second].first,h[best.first][best.second].second)
        }
        for(i in 0..n-1) print("${c[i]}")
        print("\n")
    }
}