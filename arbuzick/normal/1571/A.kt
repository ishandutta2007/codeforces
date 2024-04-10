fun main() {
    var t = readLine()!!.toInt()
    for (i in 0 until t) {
        var s = readLine()!!
        var cnt1 = 0
        var cnt2 = 0
        var cnt3 = 0
        for (ch in s) {
            if (ch == '<') {
                cnt1 += 1
            }
            if (ch == '=') {
                cnt2 += 1
            }
            if (ch == '>') {
                cnt3 += 1
            }
        }
        if (cnt1 > 0 && cnt3 > 0) {
            println('?')
        } else {
            if (cnt1 > 0) {
                println('<') 
            } else {
                if (cnt3 > 0) {
                    println('>')
                } else {
                     println('=')
                }
            }
        }
    }
}