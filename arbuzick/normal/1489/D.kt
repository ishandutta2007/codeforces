

fun main() {
    var n = readLine()!!.toInt()
    var ar = MutableList<Pair<Int, String>>(0){Pair(0, "")}
    for (i in 0 until n) {
        var arg = readLine()!!
        ar.add(Pair(arg.length, arg))
    }
    ar.sortWith(compareBy<Pair<Int, String>>({it.first}, {it.second}))
    var ans = 1
    for (i in 1 until n) {
        var ans1 = 0
        for (j in 0 until (ar[i].first - ar[i - 1].first + 1)) {
            for (l in 0 until ar[i - 1].first) {
                if (ar[i].second[j + l] != ar[i - 1].second[l]) {
                    break
                }
                if (l == ar[i - 1].first - 1) {
                    ans1 = 1
                    break
                }
            }
            if (ans1 == 1) {
                break
            }
        }
        if (ans1 == 0) {
            ans = 0
            break
        }
    }
    if (ans == 1) {
        println("YES")
        for (i in 0 until n) {
            println(ar[i].second)
        }
    } else {
        print("NO")
    }
}