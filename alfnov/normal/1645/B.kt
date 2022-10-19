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
//    val reader=Scanner(System.`in`)
    var T=1
    while(T>0){
        T=T-1
        var n=readInt()
        var ss=readLine().toString()
        var gs=0
        var wz=0
        while(wz<n){
            print(ss[wz])
            gs=gs+1;wz=wz+gs
        }
        print('\n')
    }
}