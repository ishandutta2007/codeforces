import kotlin.math.min

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() }// list of ints

fun square(a: Int) : Int
{
    return a*a
}


fun printer(a: IntArray) : Unit
{
    var n = a.size
    for (i in 0..(n-1))
    {
        print(a[i])
        print(' ')
    }
    println(' ')
}



fun main() {


    var q = readInt()


    repeat(q)
    {
        var s = readLn()
        var t = readLn()
        var m = s.length
        var n = t.length
        var curs = 0
        var curt = 0
        while (curs<m&&curt<n) {
            if (t[curt] == '-') {
                if (s[curs] == '-') {
                    curt++
                    curs++
                } else {
                    break
                }
            } else {
                if (s[curs] == '+') {
                    curt++
                    curs++
                } else {
                    if (curs == m - 1 || s[curs] != '-' || s[curs + 1] != '-') break
                    else {
                        curt++
                        curs += 2
                    }
                }
            }
        }
        if (curs==m&&curt==n) println("YES")
        else println("NO")
    }

    /*var (n, m, k) = readInts()
    var col: IntArray = readInts().toIntArray()
    var g = MutableList<MutableList<Int>>(n) { i ->
        mutableListOf<Int>()
    }

    for (i in 0..(m-1)){
        var (a, b) = readInts()
        a--
        b--
        g[a].add(b)
        g[b].add(a)
    }

    var visited = MutableList<Boolean>(n) {i -> false}

    var neighbours = MutableList<MutableList<Int>>(0) {i->mutableListOf<Int>()}

    var cur: Int = -1
    fun dfs(a: Int) : Unit
    {
        visited[a] = true
        neighbours[cur].add(a)
        for (t in g[a])
        {
            if (visited[t] == false) dfs(t)
        }
    }

    for (i in 0..(n-1))
    {
        if (visited[i]==false){
            cur++
            neighbours.add(mutableListOf<Int>())
            dfs(i)
        }
    }

    for*/



}