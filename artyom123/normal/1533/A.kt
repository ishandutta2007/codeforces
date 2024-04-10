import java.util.*
import kotlin.math.*
 
fun main(args: Array<String>) {
    val sc = Scanner(System.`in`)
    var T = sc.nextInt()
    while (T-- > 0) {
        var n = sc.nextInt()
        var k = sc.nextInt()
        var ans = 0
        for (i in 1..n) {
            var l = sc.nextInt()
            var r = sc.nextInt()
            if (l > k) continue
            if (l < k) l = k
            if (ans < r - l + 1) {
                ans = r - l + 1
            }
        }
        println(ans)
    }
}