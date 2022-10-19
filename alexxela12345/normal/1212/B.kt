private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    val n = readInt();
    val s = readLn();
    val counter = HashMap<String, Int>();
    for (i in 0..n - 2) {
        val s2 = s.slice(i..i + 1);
        var cnt = counter[s2];
        if (cnt == null) {
            cnt = 1;
        } else {
            cnt += 1;
        }
        counter.set(s2, cnt);
    }
    var max_ans = 0;
    var max_s = "";
    for (el in counter) {
        if (el.value > max_ans) {
            max_ans = el.value;
            max_s = el.key;
        }
    }
    println(max_s);
}