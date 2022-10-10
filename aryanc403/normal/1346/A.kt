import java.math.BigInteger

fun readInt(): Int {
    return readLine()!!.toInt()
}

fun readLong(): Long {
    return readLine()!!.toLong()
}

fun readBigInt(): BigInteger {
    return readLine()!!.toBigInteger()
}

fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

fun readLongs(): List<Long> {
    return readLine()!!.split(" ").map(String::toLong)
}

fun readBigInts(): List<BigInteger> {
    return readLine()!!.split(" ").map(String::toBigInteger)
}

fun main() {
    val t = readInt()
    for (i in 0 until t) {
        val cc = readInts()
        val a=cc[0]
        val b=cc[1]
        val c = a/(1+b+b*b+b*b*b)
        println(c)
        println(c*b)
        println(c*b*b)
        println(c*b*b*b)
    }
}
//https://codeforces.com/contest/1347/submission/80937320