import java.lang.Long.min

private fun readLn()=readLine()!!
private fun readInt()=readLn().toInt()
private fun readLong()=readLn().toLong()
private fun readStrings()=readLn().split(" ")
private fun readInts()=readStrings().map{it.toInt()}.toMutableList()
private fun readLongs()=readStrings().map{it.toLong()}.toMutableList()

fun main()
{
    val (n,m,k)=readInts()
    var a=readLongs()
    a.sort()
    var now:Long=0
    var x:Long=a[0]-1
    var idx=0
    for(i in 0..m-2) now+=(a[i]-x)
    var res=(1L shl 60)
    var inc:Long=0
    for(i in -1..n-1-m)
    {
        now+=(a[i+m]-x)
        if(i>=0)
        {
            now-=(x-a[i])
            inc-=(x-a[i])
        }
        /*print("now [")
        for(j in i+1..i+m) print("${a[j]} ")
        println("]")*/
        while(true)
        {
            var l=idx-(i+1)
            var r=m-l
            if(l<=r)
            {
                var y=if(l>0) min(a[idx],(k-inc+x*l)/l) else a[idx]
                if(x<y)
                {
                    now+=(l-r)*(y-x);
                    inc+=(l*(y-x))
                    if(y==a[idx])
                    {
                        while(idx<n&&a[idx]==y) idx++
                    }
                    x=y
                }
                else break
            }
            else break
        }
//        println("x=$x")
//        println("now=$now")
        res=min(res,now)
    }
    print("${res}\n")
}