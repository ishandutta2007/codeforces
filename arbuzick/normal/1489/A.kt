fun main() {
    var n = readLine()!!.toInt()
    var a = readLine()!!.split(' ').map { it.toInt() }
    var b = MutableList<Int>(0) { 0 }
    for (i in 0 until n) {
        var f = 1
        for (j in i + 1 until n) {
            if (a[j] == a[i]) {
                f = 0
                break
            }
        }
        if (f == 1) {
            b.add(a[i])
        }
    }
    println(b.size)
    for (i in b) {
        print(i)
        print(' ')
    }
}