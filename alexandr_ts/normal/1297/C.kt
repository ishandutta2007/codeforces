private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    var t = readInt()
    for (it in 0..t-1) {
        var n = readInt()
        val a = readInts().toIntArray()
        var i1 = -1
        var val1 = 100000
        var i2 = -1
        var val2 = 100000
        var cntpos = 0
        for (i in 0..n-1) {
            if (a[i] > 0) {
                cntpos += a[i]
                if (i1 == -1 || val1 > a[i]) {
                    i1 = i
                    val1 = a[i]
                }
            } else if (a[i] < 0) {
                if (i2 == -1 || val2 > -a[i]) {
                    i2 = i
                    val2 = -a[i]
                }
            }
        }
        
        if (i2 == -1 || val2 > val1) {
            println(cntpos - val1) 
            for (i in 0..n-1) {
                if (a[i] > 0 && i != i1) {
                    print(1)
                } else {
                    print(0)
                }
            }
            println("")
        } else {
            println(cntpos - val2) 

            for (i in 0..n-1) {
                if (a[i] > 0 || i == i2) {
                    print(1)
                } else {
                    print(0)
                }
            }
            println("")

        }
    }
}