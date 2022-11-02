
class Obj : Comparable<Obj>{
    var l: Int = 0
    var r: Int = 0
    var ind: Int = 0
    override fun compareTo(other: Obj): Int = this.l.compareTo(other.l)
}

fun solve() {
    var (n, k) = readLine()!!.split(" ").map{it.toInt()}
    var s = readLine()!!
    var bal = 0
    var cnt = 0
    for (i in 0 until n) {
        if(s[i] == ')') bal--
        else bal++
        if (bal < 0) {
            break
        }
        if(bal == 0) {
            cnt++
        }
    }
    var cnt2 = 0
    bal = 0
    for(i in 0 until n) {
        if(s[i] == ')') {
            if(bal > 0) {
                bal--
                cnt2++
            }
        } else {
            bal++
        }
    }
    if(cnt2 <= k) {
        println(cnt2)
        return
    }
    if(cnt2 - cnt <= k) {
        println(cnt2)
        return
    }
    println(cnt + k)
}


fun main(args: Array<String>) {
    //println("Hello World!")
    var t = 1
    t = readLine()!!.toInt()
    for (i in 0 until t) {
        solve()
    }
}