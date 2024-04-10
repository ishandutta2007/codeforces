import java.util.*
fun foo(){
    val n=readLine()!!.toInt()
    var numbers = ArrayList<Triple<Int,Int,Int>>()
    val ans: MutableList<Int> = mutableListOf()
    for(i in 0..n-1){
            val (a,b)=readLine()!!.split(" ").map { it.toInt()}
        numbers.add(Triple(a,b,i))
        ans.add(1)
    }
    var sortednumbers = numbers.sortedWith(compareBy({ it.first }))
    var r=sortednumbers[0].second
    ans[sortednumbers[0].third] = 2
    for(i in 1..n){
        if(i==n){
            println(-1)
            return
        }
        if(sortednumbers[i].first>r){
            break;
        }
        if(sortednumbers[i].second>r){
            r = sortednumbers[i].second
        }
        ans[sortednumbers[i].third] = 2
    }
    for(i in 0..n-2){
        print(ans[i])
        print(" ")
    }
    println(ans[n-1])
}
fun main(args: Array<String>) {
    val n=readLine()!!.toInt()
    for(i in 1..n){
        foo()
    }
}