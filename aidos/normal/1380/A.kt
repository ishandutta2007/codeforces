

fun solve(){
    var n = readLine()!!.toInt()
    var a = readLine()!!.split(" ").map{it.toInt()}
    for(i in 1 until n-1) {
        if(a[i-1] < a[i] && a[i] > a[i + 1]) {
            println("YES")
            print(i)
            print(" ")
            print(i+1)
            print(" ")
            println(i+2)
            return
        }
    }
    println("NO")

}

fun main() {
    var t = readLine()!!.toInt()
    for (i in 0 until t) {
        solve()
    }
}