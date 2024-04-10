fun main(args: Array<String>) {
    val n=readLine()!!.toInt()
    val s = readLine()!!
    if(n>26 || n==1){
        println("Yes")
        return
    }
    var work = false
    for(i in 0..25){
        var sum=0
        for(j in 0..n-1){
            if(s[j]-'a'==i){
                sum++
            }
        }
        if(sum>=2){
            work=true
            break
        }
    }
    if(work){
        println("Yes")
    } else {
        println("No")
    }
}