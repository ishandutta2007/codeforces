fun main(args: Array<String>) {
    var t = readLine()!!.toInt()
    while(t>0){
        val n = readLine()!!.toInt()
    
        if(n<1000)
            println(n);
        else if(n<999500){
            val k=(n+500)/1000
            println(k.toString()+"K")
        }
        else
        {
            val k=(n+500000)/1000000
            println(k.toString()+"M")
        }
        t--
    }
}