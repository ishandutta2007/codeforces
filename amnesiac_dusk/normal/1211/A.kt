import java.util.*
 
fun main() {
    val sc = Scanner(System.`in`)
 
    var n=sc.nextInt()
    var a=IntArray(n+1)
    a[0]=0
    var min1=0
    var min2=0
    var min3=0
    for(i in 1 until n+1) {
        a[i]=sc.nextInt()
        if(a[min1]<a[i]) {
            min3=min2
            min2=min1
            min1=i
        } else if(a[min1]==a[i]){
        
        }
        else if(a[min2]<a[i]) {
            min3=min2
            min2=i
        } else if(a[min2]==a[i]){
        
        } else if(a[min3]<a[i]) {
            min3=i
        }
    }
    if(min3==0)
        println("-1 -1 -1")
    else {
        print(min3)
        print(" ")
        print(min2)
        print(" ")
        println(min1)
    }
}