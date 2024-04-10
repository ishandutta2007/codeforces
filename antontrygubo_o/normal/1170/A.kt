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


    var q: Int = readInt()
    repeat(q)
    {
        var(x, y) = readInts()
        var z = min(x, y) - 1
        print(x-z)
        print(' ')
        print(z)
        print(' ')
        println(y-z)
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