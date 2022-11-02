
fun solve(){
    var c1 = 0;
    var c2 = 0;
    var ans = 0;
    var s = readLine()!!
    for (c in s) {
        if(c == '(') c1++;
        else if(c == '[') c2++;
        else if(c == ')') {
            if(c1 > 0) {
                c1--;
                ans++;
            }
        } else if(c2 > 0) {
            c2--;
            ans++;
        }
    }
    println(ans);
}

fun main() {
    var t = readLine()!!.toInt()
    for (i in 0 until t) {
        solve()
    }
}