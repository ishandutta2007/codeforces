

fun solve(){
    var s = readLine()!!.toCharArray()
    var K = 400
    var a = IntArray(s.size + K + 10)
    var b = IntArray(s.size + K + 10)
    for (i in 0 until s.size) {
        var c = s[i].toByte().toInt() - 'a'.toByte().toInt()
        a[i] = 1 shl c
        b[i/K] = b[i/K] or a[i]
    }

    var q = readLine()!!.toInt()

    for(i in 0 until q) {
        var (type, x, y) = readLine()!!.split(" ")
        if(type[0] == '1') {
            var pos = x.toInt() - 1
            s[pos] = y[0]
            var c = s[pos].toByte().toInt() - 'a'.toByte().toInt()
            a[pos] = 1 shl c
            var bl = pos/K
            b[bl] = 0
            for(j in bl * K until bl * K + K) {
                b[bl] = b[bl] or a[j]
            }
        } else {
            var l = x.toInt() - 1
            var r = y.toInt()
            var ans = 0
            while(l < r) {
                if(l % K == 0 && l + K < r) {
                    ans = ans or b[l/K]
                    l += K
                } else {
                    ans = ans or a[l]
                    l++
                }
            }
            var cnt = 0
            while(ans > 0) {
                cnt += ans % 2
                ans /= 2
            }
            println(cnt)
        }
    }
}

fun main() {
    var t = 1//readLine()!!.toInt()
    for (i in 0 until t) {
        solve()
    }
}