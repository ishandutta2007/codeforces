
fun solve(){
    var n = readLine()!!.toInt()
    var a = readLine()!!.split(' ').map{it.toInt()}
    var b = ArrayList<Int>()
    for(x in a.reversed()) {
        var ok = true
        for(y in b) {
            if(x == y) ok = false
        }
        if(ok) {
            b.add(x)
        }
    }
    b.reverse()
    println(b.size)
    println(b.joinToString(" "))
}


fun main(args: Array<String>) {
    //println("Hello World!")
    var t = 1//readLine()!!.toInt()
    for (i in 0 until t) {
        solve()
    }
}