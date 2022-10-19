import java.lang.AssertionError
private fun readLn()=readLine()!!
private fun readInt()=readLn().toInt()
private fun readLong()=readLn().toLong()
private fun readDouble()=readLn().toDouble()
private fun readStrings()=readLn().split(" ")
private fun readInts()=readStrings().map{it.toInt()}
private fun readLongs()=readStrings().map{it.toLong()}
private fun readDoubles()=readStrings().map{it.toDouble()}
fun main(){
    var a1=readInt()
    var a2=readInt()
    var k1=readInt()
    var k2=readInt()
    var n=readInt()
    var mn=0
    var mx=0
    if(n<=a1*(k1-1)+a2*(k2-1))mn=0
    else mn=n-a1*(k1-1)-a2*(k2-1)
    if(k1>k2){
        a1=a2.also{
            a2=a1
        }
        k1=k2.also{
            k2=k1
        }
    }
    if(a1*k1>=n){
        mx=n/k1
    }else{
        mx=a1
        n=n-k1*a1
        mx=mx+n/k2
    }
    print(mn)
    print(' ')
    println(mx)
}