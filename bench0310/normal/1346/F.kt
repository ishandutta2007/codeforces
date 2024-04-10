import kotlin.math.min

private fun readLn()=readLine()!!
private fun readInt()=readLn().toInt()
private fun readLong()=readLn().toLong()
private fun readStrings()=readLn().split(" ")
private fun readInts()=readStrings().map {it.toInt()}.toMutableList()
private fun readLongs()=readStrings().map {it.toLong()}.toMutableList()

fun main()
{
    var (n,m,q)=readInts()
    var a=MutableList(n+1,{MutableList(m+1,{0L})})
    for(i in 1..n)
    {
        var tmp=readLongs()
        for(j in 1..m) a[i][j]=tmp[j-1]
    }
    var row=MutableList(n+1,{0L})
    var col=MutableList(m+1,{0L})
    for(i in 1..n)
    {
        for(j in 1..m)
        {
            row[i]+=a[i][j]
            col[j]+=a[i][j]
        }
    }
    fun solve():Unit
    {
        var up=MutableList(n+1,{0L})
        var sum:Long=0
        for(i in 1..n)
        {
            up[i]=up[i-1]+sum
            sum+=row[i]
        }
        var down=MutableList(n+2,{0L})
        sum=0
        for(i in n downTo 1)
        {
            down[i]=down[i+1]+sum
            sum+=row[i]
        }
        var one=up[n]
        for(i in 1..n) one=min(one,up[i]+down[i])
        var left=MutableList(m+1,{0L})
        sum=0
        for(i in 1..m)
        {
            left[i]=left[i-1]+sum
            sum+=col[i]
        }
        var right=MutableList(m+2,{0L})
        sum=0
        for(i in m downTo 1)
        {
            right[i]=right[i+1]+sum
            sum+=col[i]
        }
        var two=left[m]
        for(i in 1..m) two=min(two,left[i]+right[i])
        print("${one+two} ")
    }
    solve()
    while((q--)>0)
    {
        var (x,y,z)=readInts()
        var d=z-a[x][y]
        row[x]+=d
        col[y]+=d
        a[x][y]=z.toLong()
        solve()
    }
    print("\n")
}