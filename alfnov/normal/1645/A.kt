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
    var T=reader.nextInt()
    while(T>0){
        T=T-1
        var n=reader.nextInt()
        var a=ArrayList<Int>()
        for(i in 0 until n){
            var b=reader.nextInt()
            a.add(b)
        }
        var wz=0
        for(i in 0 until n){
            var gs=0
            for(j in 0 until n){
                if(a[i]==a[j])gs=gs+1
            }
            if(gs<=1)wz=wz+i+1
        }
        print(wz)
        print('\n')
    }
}