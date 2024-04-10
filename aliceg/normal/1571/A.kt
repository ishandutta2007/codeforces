private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
    val t = readInt()
    repeat(t) {
        val s = readLn()
        var c = '='
        s.forEach { x ->
            if (c == '?')
                return@forEach
            if (x == '>' && c == '<')
                c = '?'
            else if (x == '>')
                c = '>'
            if (x == '<' && c == '>')
                c = '?'
            else if (x == '<')
                c = '<'
        }
        println(c)
    }
}