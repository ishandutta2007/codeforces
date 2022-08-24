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
        val t = nextInt()
        for (tc in 0 until t) {
            val n = nextInt()
            val a = IntArray(n)
            for (i in 0 until n) {
                a[i] = nextInt()
            }
            Arrays.sort(a)
            val vals = IntArray(n)
            val x = IntArray(n)
            var ptr = 0
            var mda = 0
            while (ptr < n) {
                var j = ptr
                while (j < n && a[j] == a[ptr]) {
                    j++
                }
                x[mda] = a[ptr]
                vals[mda++] = j - ptr
                ptr = j
            }
            var vl = 0
            var vr = n + 1
            while (vl < vr - 1) {
                val vm = (vl + vr) / 2
                var sum = 0
                for (i in 0 until mda) {
                    sum += Math.min(vals[i], vm / 2)
                }
                if (vm % 2 == 1 && (vals[0] >= (vm + 1) / 2 || vals[mda - 1] >= (vm + 1) / 2)) {
                    sum++
                }
                if (sum >= vm) {
                    vl = vm
                } else {
                    vr = vm
                }
            }
            val arr = IntArray(vl)
            var kek = 0
            var kekos = false
            for (i in 0 until mda) {
                var grab = Math.min(vals[i], vl / 2)
                if (vl % 2 == 1 && i == 0 && vals[i] >= (vl + 1) / 2) {
                    kekos = true
                    grab++
                }
                if (!kekos && vl % 2 == 1 && i == mda - 1 && vals[i] >= (vl + 1) / 2) {
                    grab++
                }
                for (j in 0 until grab) {
                    if (kek < vl) {
                        arr[kek] = x[i]
                        kek++
                    }
                }
            }
            out.println(vl)
            val k = (vl + 1) / 2
            val ans = IntArray(vl)
            for (i in 0 until vl) {
                if (i % 2 == 0) {
                    ans[i] = arr[i / 2]
                } else {
                    ans[i] = arr[i / 2 + k]
                }
            }
            var bad = false
            for (i in 1 until vl) {
                if (ans[i] == ans[i - 1]) bad = true
            }
            if (!bad) {
                for (i in 0 until vl) out.print(ans[i].toString() + " ")
                out.println()
            } else {
                for (i in 0 until vl) {
                    if (i % 2 == 0) {
                        ans[i] = arr[i / 2 + vl / 2]
                    } else {
                        ans[i] = arr[i / 2]
                    }
                }
                for (i in 0 until vl) out.print(ans[i].toString() + " ")
                out.println()
            }
        }
    }

    fun main(args: Array<String>) {
        solve()
        out.close()
    }