fun main() {
    val n = readLine()!!.toInt()
    val s = readLine()!!
        .split(' ')
        .map(String::toInt)
        .toIntArray()

    var first = -1
    var second = -1
    var ans = 0

    for (i in 0..(n-1)) {
        if (first <= s[i]) {
            second = first
            first = s[i]
        } else if (second <= s[i]) {
            second = s[i]
        }

        if (second > s[i]) {
            ans += 1
        }
    }

    println(ans)
}