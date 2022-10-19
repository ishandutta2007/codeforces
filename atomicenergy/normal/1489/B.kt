

fun main(args: Array<String>) {
    var t = readLine()!!.toLong()
    for(q in 0..t-1){
        var v = readLine()!!.split(" ").map{i -> i.toLong()};
        if(v[1] * 2 < v[2]){
            println(v[0] * v[1])
        }else{
            println(v[0]/2 * v[2] + v[0]%2 * v[1])
        }
    }
    
}