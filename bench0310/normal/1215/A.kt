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
    var m=readInt()
    var x=readInt()
    var y=readInt()
    var c=readInt()
    var mn=maxOf(0,c-n*(x-1)-m*(y-1))
    var a=mutableListOf<Int>()
    for(i in 1..n) a.add(x)
    for(i in 1..m) a.add(y)
    if(x>y) a.reverse()
    var mx=0
    var now=c
    for(k in a)
    {
        if(k<=now)
        {
            mx++
            now-=k
        }
    }
    print("${mn} ${mx}\n")
}