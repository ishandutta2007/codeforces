import java.io.*
import java.math.BigDecimal
import java.math.BigInteger
import java.nio.charset.IllegalCharsetNameException
import java.util.*


    internal var br = BufferedReader(InputStreamReader(System.`in`))
    internal var st: StringTokenizer? = null
    internal var out = PrintWriter(System.out)

    @Throws(IOException::class)
    internal  fun next(): String {
        while (st == null || !st!!.hasMoreTokens()) {
            st = StringTokenizer(br.readLine())
        }
        return st!!.nextToken()
    }

    @Throws(IOException::class)
    internal fun nextInt(): Int {
        return Integer.parseInt(next())
    }

    @Throws(IOException::class)
    internal fun nextLong(): Long {
        return java.lang.Long.parseLong(next())
    }

    @Throws(IOException::class)
    internal fun solve() {
        val n = nextInt()
        val m = nextInt()
        val k = nextInt()
        val a = IntArray(n)
        for (i in 0 until n) {
            a[i] = nextInt()
            val x = (0..i).random();
            val t = a[i];
            a[i] = a[x];
            a[x] = t;
        }
        Arrays.sort(a)
        val pr = LongArray(n + 1)
        for (i in 0 until n) pr[i + 1] = pr[i] + a[i]
        var ans = pr[n]
        var i = 0
        var ptr = 0;
        while (i + m - 1 < n) {
            val l = i
            val r = i + m - 1
            val mid = (l + r) / 2
            var sum = (mid - l) * a[mid].toLong() - (pr[mid] - pr[l])
            if (sum <= k) {
                sum += pr[r + 1] - pr[mid] - (r + 1 - mid) * a[mid].toLong()
                ans = Math.min(ans, sum)
            } else {
                sum += pr[r + 1] - pr[mid] - (r + 1 - mid) * a[mid].toLong()
                if (sum > ans) {
                    i++;
                    continue;
                }
                ptr = Math.max(ptr, l);
                while (ptr + 1 < r) {
                    val vm = ptr + 1;
                    val sm = (vm + 1 - l) * a[vm].toLong() - (pr[vm + 1] - pr[l])
                    if (sm <= k) {
                        ptr++;
                    } else {
                        break;
                    }
                }
                val vl = ptr;
                var ret = (vl + 1 - l) * a[vl].toLong() - (pr[vl + 1] - pr[l])
                var `val` = a[vl].toLong()
                `val` += (k - ret) / (vl - l + 1)
                ret = (vl - l + 1) * `val` - (pr[vl + 1] - pr[l])
                ret += pr[r + 1] - pr[vl + 1] - (r + 1 - (vl + 1)) * `val`
                ans = Math.min(ans, ret)
            }
            i++
        }
        out.println(ans)
    }

    fun main(args: Array<String>) {
        solve()
        out.close()
    }