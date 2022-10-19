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
        var b=ArrayList<Int>()
        var c=ArrayList<Int>()
        var wz=0
        var flag=1
        while(wz<n){
            var zw=wz
            while(zw<n&&a[zw]==a[wz])
                zw=zw+1
            var le=zw-wz
            if(le>2){
                flag=0
                break
            }
            b.add(a[wz])
            if(le==2)c.add(-a[wz])
            wz=zw;
        }
        b.sort()
        c.sort()
        if(flag==1){
            print("YES\n")
            var A=b.size
            var B=c.size
            print(A)
            print('\n')
            for(i in 0 until A){
                print(b[i])
                print(' ')
            }
            print('\n')
            print(B)
            print('\n')
            for(i in 0 until B){
                print(-c[i])
                print(' ')
            }
            print('\n')
        }
        else print("NO\n")
    }
}