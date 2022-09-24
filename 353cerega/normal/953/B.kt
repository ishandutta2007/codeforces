import java.io.*;

fun gcd(a: Int, b: Int): Int {
    if (a == 0) return b
    else return gcd(b%a, a)
}

fun main(arg: Array<String>){
    val n = readLine()!!.toInt()
    val b = readLine()!!.split(' ').map(String::toInt)
    val a = b.toTypedArray()
    a.sort()
    var g = 0
    for(i in 1..(n-1)){
        g = gcd(g, a[i] - a[i - 1])
    }
    var ans = 0
    for(i in 1..(n-1)){
        ans = ans + (a[i] - a[i - 1])/g - 1
    }
    println(ans);
}