
fun solve(){
    var s = readLine()!!
    var t = "";
    for (i in 0 until s.length) {
        if(i % 2 == 0) {
            if(s[i] == 'a') t += 'b';
            else t += 'a';
        } else {
            if(s[i] == 'z') t += 'y';
            else t += 'z';
        }
    }
    println(t);
}

fun main() {
    var t = readLine()!!.toInt()
    for (i in 0 until t) {
        solve()
    }
}