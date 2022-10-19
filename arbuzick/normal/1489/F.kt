fun main() {
    var args = readLine()!!.split(' ').map{ it.toInt() }
    var n = args[0]
    var m = args[1]
    var k = args[2]
    var a = readLine()!!.split(' ').map{ it.toInt() }
    var l = -1
    var r = n
    while (l < r - 1) {
        var m1 = (l + r) / 2
        var cnt = m - 1
        var cur = k
        for (i in m1..(n-1)) {
            if (cur >= a[i]) {
                cur -= a[i]
            } else {
                cnt -= 1
                cur = k - a[i];
            }
        }
        if (cnt >= 0) {
            r = m1
        } else {
            l = m1
        }
    }
    print(n - r)
}