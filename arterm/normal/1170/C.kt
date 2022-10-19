fun solveC(): Boolean {
    val t = readLine()!!.toCharArray()
    val s = readLine()!!.toCharArray()

    var j = 0
    for (i in 0 until s.size) {
        if (j >= t.size) {
            return false
        }

        if (s[i] == t[j]) {
            j += 1
            continue
        }

        if (s[i] == '+' && j + 1 < t.size && t[j] == '-' && t[j + 1] == '-') {
            j += 2
            continue
        } else {
            return false
        }
    }

    return j == t.size
}


fun main() {
    val t = readLine()!!.toInt()
    for (i in 1..t) {
        if (solveC())
            println("YES")
        else
            println("NO")
    }
}