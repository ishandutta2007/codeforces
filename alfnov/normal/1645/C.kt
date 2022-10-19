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
        for(i in 0 until n){
            for(j in i+1 until n){
                if(a[i]>a[j]){
                    a[i]=a[j].also{
                        a[j]=a[i]
                    }
                }
            }
        }
        var ans=0.toLong()
        var wz=0
        while(wz<n){
            ans=ans+a[wz+1]-a[wz]
            wz=wz+2
        }
        print(ans)
        print('\n')
    }
}