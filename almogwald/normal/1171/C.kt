fun foo(){
    var n = readLine()!!
    if(n != n.reversed()){
        println(n)
    }else{
        n = n.substring(1)+n.substring(0,1)
        if(n != n.reversed()){
            println(n)
        }else{
            println(-1)
        }
    }
}

fun main(args: Array<String>) {
    var n = readLine()!!.toInt() 
    for (i in 1..n) {
        foo()
    }
}