

fun ask(a: Int, n: Int): Int{
    if(a == 0 || a == n + 1) {
        return 100001000
    }
    print("? ")
    println(a)
    var ans = readLine()!!.toInt()
    return ans
}
fun solve(){
    var n = readLine()!!.toInt()
    var l = 1
    var r = n
    while(l <= r) {
        var mid = (l + r)/2
        var cur = ask(mid, n)
        if(ask(mid-1, n) < cur) {
            r = mid-1
        } else if(ask(mid+1, n) < cur) {
            l = mid+1
        } else {
            print("! ")
            println(mid)
            return
        }
    }
}

fun main() {
    var t = 1//readLine()!!.toInt()
    for (i in 0 until t) {
        solve()
    }
}