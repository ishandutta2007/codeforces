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
        var k=reader.nextInt()
        var a=ArrayList<Int>()
        for(i in 0 until 31)a.add(0)
        var gs=0
        for(i_Jia in -30 until 1){
            var i=-i_Jia
            if(n>=(1 shl i)){
                n-=1 shl i
                a[i]=1
                gs=gs+1
            }
        }
        if(k<gs){
            print("NO\n")
            continue
        }
        var ff=1
        for(i in gs+1 until k+1){
            var flag=0
            for(j_Jia in -30 until 0){
                var j=-j_Jia
                if(a[j]==0)continue
                flag=1
                a[j-1]+=2
                a[j]-=1
                break
            }
            if(flag==0)ff=0
        }
        if(ff==0)print("NO\n")
        else{
            print("YES\n")
            for(i in 0 until 31){
                for(j in 0 until a[i]){
                    print(1 shl i)
                    print(' ')
                }
            }
            print('\n')
        }
    }
}