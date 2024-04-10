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


    var n = readInt()

    var max1 = 0
    var max2 = 0
    var cnt = 0
    var b = readInts()
    for (a in b)
    {

        if (max2>a) cnt++

        if (a>=max1)
        {
            max2 = max1
            max1 = a
        }
        else if (a>=max2)
        {
            max2 = a
        }
    }
    print(cnt)
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