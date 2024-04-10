private fun readLn()=readLine()!!
private fun readInt()=readLn().toInt()
private fun readLong()=readLn().toLong()
private fun readStrings()=readLn().split(" ")
private fun readInts()=readStrings().map{it.toInt()}.toMutableList()
private fun readLongs()=readStrings().map{it.toLong()}.toMutableList()

fun main()
{
    var (n,m)=readInts()
    var a=readInts()
    var sum=MutableList<Int>(n,{0})
    sum[0]=a[0]
    for(i in 1..n-1) sum[i]=sum[i-1]+a[i]
    fun s(l:Int,r:Int):Int{return sum[r]-(if(l>0) sum[l-1] else 0)}
    var q=readInt()
    while((q--)>0)
    {
        var w=readInts()
        w.add(m+1)
        var now=1
        var idx=0
        for(i in 1..w.size-1)
        {
            var x=w[i]
            var opt=x-1-now+1
            var l=idx-1
            var r=n
            while(l<r-1)
            {
                var mid=(l+r)/2
                if(s(idx,mid)<=opt) l=mid
                else r=mid
            }
            idx=r
            now=x+1
        }
        if(idx==n) print("YES\n") else print("NO\n")
    }
}