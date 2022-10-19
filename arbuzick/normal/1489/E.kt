

fun main() {
    var n: Int = (2e5 + 5).toInt()
    var q = readLine()!!.toInt()
    var l = MutableList<Int>(n) {0}
    var r = MutableList<Int>(n) {0}
    var l2 = MutableList<Int>(n) {0}
    var r2 = MutableList<Int>(n) {0}
    var l1 = 0
    var r1 = 0
    for (q1 in 0 until q) {
        var arg = readLine()!!.split(' ')
        if (arg[0] == "L") {
            l1 += 1
            l[arg[1].toInt()] = l1
            r[arg[1].toInt()] = r1
            l2[arg[1].toInt()] = 0
            r2[arg[1].toInt()] = l1 + r1 - 1
        } else if (arg[0] == "R") {
            r1 += 1
            l[arg[1].toInt()] = l1
            r[arg[1].toInt()] = r1
            l2[arg[1].toInt()] = l1 + r1 - 1
            r2[arg[1].toInt()] = 0
        } else {
            if (r1 - r[arg[1].toInt()] + r2[arg[1].toInt()] < l1 - l[arg[1].toInt()] + l2[arg[1].toInt()]) {
                println(r1 - r[arg[1].toInt()] + r2[arg[1].toInt()])
            } else {
                println(l1 - l[arg[1].toInt()] + l2[arg[1].toInt()])
            }
        }
    }
}