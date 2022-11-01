private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    var t = readInt()
    for (it in 0..t-1) {
        var (n, m) = readInts()
        var a = mutableListOf<MutableList<Int>>()
        var a_inp = mutableListOf<Int>()
        for (i in 0..n-1) {
            var (l, r) = readInts()
            a.add(mutableListOf(l, r, i))
            a_inp.add(r)
        }
        var ansday = mutableListOf<Int>()
        for (i in 0..n-1) {
            ansday.add(0)
        }
        
        a = a.sortedWith(compareBy({it[0]}, {it[1]}, {it[2]})).toMutableList()
        
        var s = sortedSetOf<MutableList<Int>>(compareBy({it[1]}, {it[0]}, {it[2]}))
       
        var cur_day = 0 
        var ptr = 0
        
        while (s.size > 0 || ptr < a.size) {
            if (s.size == 0 && ptr < a.size) {
                cur_day = maxOf(cur_day, a[ptr][0])
            }
            while (ptr < a.size && a[ptr][0] == cur_day) {
                s.add(a[ptr])
                ptr += 1
            }
            
            var iters = minOf(m, s.size)
            for (j in 0..iters-1) {
                var todel = s.first()
                ansday[todel[2]] = cur_day
                s.remove(todel)
            }
            
            cur_day += 1
        }
        
        var ansd = 0
        for (i in 0..n-1) {
            if (ansday[i] > a_inp[i]) {
                ansd = maxOf(ansd, ansday[i] - a_inp[i])
            }
        }
        
        println(ansd)
        for (i in 0..n-1) {
            print(ansday[i].toString() + " ")
        }
        println("")
    }
}