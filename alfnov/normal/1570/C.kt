import java.lang.AssertionError
import java.util.Scanner
private fun readLn()=readLine()!!
private fun readInt()=readLn().toInt()
private fun readLong()=readLn().toLong()
private fun readDouble()=readLn().toDouble()
private fun readStrings()=readLn().split(" ")
private fun readInts()=readStrings().map{it.toInt()}
private fun readLongs()=readStrings().map{it.toLong()}
private fun readDoubles()=readStrings().map{it.toDouble()}
fun main(){
    val reader=Scanner(System.`in`)
    var n=reader.nextInt()
    var a=ArrayList<Int>()
    for(i in 0 until n){
        var s=reader.nextInt()
        a.add(s)
    }
    var b=ArrayList<Int>()
    for(i in 0 until n)b.add(i)
    for(i in 0 until n){
        for(j in i+1 until n){
            if(a[i]<a[j]){
                var ls=a[j]
                a[j]=a[i]
                a[i]=ls
                var sl=b[j]
                b[j]=b[i]
                b[i]=sl
            }
        }
    }
    var ans=0.toLong()
    for(i in 0 until n){
        ans=ans+i.toLong()*a[i]+1
    }
    print(ans)
    print('\n')
    for(i in 0 until n){
        print(b[i]+1)
        if(i==n-1){
            print('\n')
        }else{
            print(' ')
        }
    }
}