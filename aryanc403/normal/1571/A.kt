// https://codeforces.com/contest/1570/submission/130471837

import java.lang.AssertionError
 
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles
 
private fun myAssert(x: Boolean) {
    if (!x) {
        throw AssertionError()
    }
}
 
fun main(args: Array<String>) {
    var t = readInt()
    for (i in 0 until t) {
        var S = readLn()
        var n = S.length
        var a1 = false
        var a2=false
        for (j in 0 until n){
            if(S[j]=='=')
                continue
            if(S[j]=='<')
                a1=true
            if(S[j]=='>')
                a2=true
        }
        if(a1){
            if(a2)
                println('?')
            else
                println('<')
        } else {
            if(a2)
                println('>')
            else
                println('=')
        }
    }
}