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
    var T=1
    while(T>0){
        T=T-1
        var n=reader.nextInt()
        var a=ArrayList<Int>()
        for(i in 0 until n){
            var aa=reader.nextInt()
            a.add(aa)
        }
        a.sort()
        var ans=0
        var mx=0
        for(i in 0 until n){
            for(j in a[i]-1 until a[i]+2){
                if(j<=mx)continue
                mx=j;ans=ans+1
                break
            }
        }
        print(ans)
        print('\n')
    }
}