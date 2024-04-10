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
    var mx=a.maxOrNull()
    var s=Stack<Int>()
    var res=true
    for(x in a)
    {
        if(x==mx)
        {
            if(!s.isEmpty()) res=false
            continue
        }
        if(s.isEmpty()||s.peek()>x) s.push(x)
        else if(s.peek()==x) s.pop()
        else res=false
    }
    if(!s.isEmpty()) res=false
    if(res) print("YES\n")
    else print("NO\n")
}