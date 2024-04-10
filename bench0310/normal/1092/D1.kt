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
    var a=readInts()
    var c=MutableList(n,{a[it]%2})
    var v=mutableListOf<Int>()
    var now=1
    for(i in 1..n-1)
    {
        if(c[i]==c[i-1]) now++
        else
        {
            v.add(now%2)
            now=1
        }
    }
    v.add(now%2)
    var cnt=0
    var zero=false
    for(x in v)
    {
        if(x==0) zero=!zero
        else
        {
            if(zero)
            {
                if(cnt>0)
                {
                    cnt--
                    if(cnt==0) zero=false
                }
                else
                {
                    cnt=1
                    zero=false
                }
            }
            else cnt++
        }
    }
    if(cnt<=1) print("YES\n")
    else print("NO\n")
}