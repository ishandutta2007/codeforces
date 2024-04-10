private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    var t = readInt()
    for (it in 0..t-1) {
        var (n, k) = readInts()
        var g = mutableListOf<MutableList<Int>>()
        for (i in 0..n-1) {
            g.add(mutableListOf())
        }
        for (i in 0..n-2) {
            var (v, u) = readInts()
            v -= 1
            u -= 1
            g[v].add(u)
            g[u].add(v)
        }
        if (k == 1) {
            println("Yes")
            println(1)
            println(1)
            continue
        }
        var used = mutableListOf<Int>()
        var neigs = mutableListOf<Int>()
        for (i in 0..n-1) {
            used.add(0)
            neigs.add(0)
        }
        var seq = mutableListOf<Int>(0)
        var lists = 0
        var ptr = 0
        
        while (ptr < seq.size) {
            var v = seq[ptr] 
            used[v] = 1 
            for (i in 0..g[v].size-1) {
                var u = g[v][i]
                if (used[u] == 1 || lists == k) {
                    continue
                }
                used[u] = 1
                lists += 1         
                neigs[u] = 1
                neigs[v] += 1
                seq.add(u)
                if (neigs[v] == 2) {
                    lists -= 1
                } else if (neigs[v] == 1) {
                    lists += 1
                }
            }
            ptr += 1
        }
        
        if (lists < k) {
            println("No")
        } else {
            println("Yes")
            println(seq.size)
            for (i in 0..seq.size-1) {
                print((seq[i] + 1).toString() + " ")
            }
            println("")
        }
    }
}