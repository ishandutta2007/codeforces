import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*

fun scanInt(): Int {
    return scanString().toInt()
}

fun scanLong(): Long {
    return scanString().toLong()
}
private fun readLn() = readLine()!!
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun scanString(): String {
    var t = tok
    while (t == null || !t.hasMoreTokens()) {
        t = StringTokenizer(inp.readLine())
        tok = t
    }
    return t.nextToken()
}

var inp = BufferedReader(InputStreamReader(System.`in`))
var out = PrintWriter(System.out)
var tok: StringTokenizer? = null

fun main() {
    solve()
    inp.close()
    out.close()
}

class PP(var a: Int,var b: Int){
}

// A comparator to compare first names of Name
class ComparatorOne: Comparator<PP>{
    override fun compare(o1: PP?, o2: PP?): Int {
        if(o1 == null || o2 == null){
            return 0;
        }
        return o1.a.compareTo(o2.a)
    }
}


var Rank = IntArray(501000)
var SA = IntArray(501000)
var C = IntArray(501000)
var ord2 = IntArray(501000)
var wA = IntArray(501000)
var wB = IntArray(501000)

fun solve() {
    var tests = 1
    for (test in 0 until tests) {
        var n = scanInt()
        var m = scanInt()
        var Q = scanInt()

        var A = Array(n){""}

        var s = CharArray(n*m)

        for(i in 0 until n){
            var t = scanString()
            A[i] = t
            for(j in 0 until m){
                s[i*m+j] = t[j]
            }
        }

        var L = n*m
        var MM = maxOf(n*m+10, 100)

        var ord1 = IntArray(L)
        for(i in 0 until L){
            wA[i] = s[i]-'a'+1
            if(i!=L-1)wB[i] = s[i+1]-'a'+1
            else wB[i]=0
        }

        var ll = 1
        while(true){
            for(i in 0 until MM+1)C[i] = 0
            for(i in 0 until L)C[wB[i]]+=1
            for(i in 1 until MM+1)C[i] += C[i-1]
            for(i in 0 until L)ord1[--C[wB[i]]] = i

            ord1.reverse()
            for(i in 0 until MM+1)C[i] = 0
            for(i in 0 until L)C[wA[i]]+=1
            for(i in 1 until MM+1)C[i] += C[i-1]
            for(i in 0 until L)ord2[--C[wA[ord1[i]]]] = ord1[i]

            var cc = 0
            for(i in 0 until L){
                if(i == 0 || wA[ord2[i-1]]!=wA[ord2[i]] || wB[ord2[i-1]]!=wB[ord2[i]]){
                    cc+=1
                }
                Rank[ord2[i]] = cc
            }
            if(cc == L)break
            ll*=2
            for(i in 0 until L){
                wA[i] = Rank[i]
                if(i+ll<L){
                    wB[i]=Rank[i+ll]
                }
                else{
                    wB[i]=0
                }
            }
        }

        for(i in 0 until L){
            SA[Rank[i]]=i
        }


        var U = Array(m){IntArray(n){0}}
        var PV = IntArray(m)
        for(i in 1 until L+1){
            var x = SA[i]
            U[x%m][PV[x%m]++] = x/m
        }


        for(q in 0 until Q){
            var p = scanString()
            var st = 0
            var ans = 0
            while(st < m){
                var b = 0
                var e = n-1
                var last = m
                for(i in st until m){
                    var bb = b
                    var ee = e
                    var rr1 = n
                    while(bb<=ee){
                        var mm = (bb+ee)/2
                        var x = U[st][mm]
                        if(A[x][i]<p[i]){
                            bb = mm+1
                        }
                        else{
                            rr1 = mm
                            ee = mm-1
                        }
                    }
                    bb = b
                    ee = e
                    var rr2 = e+1
                    while(bb<=ee){
                        var mm = (bb+ee)/2
                        var x = U[st][mm]
                        if(A[x][i]<=p[i]){
                            bb = mm+1
                        }
                        else{
                            rr2 = mm
                            ee = mm-1
                        }
                    }
                    b = maxOf(b, rr1)
                    e = minOf(e,rr2-1)
                    if(b>e){
                        last = i
                        break
                    }
                }
                ans+=1
                if(last == st){
                    break
                }
                st = last
            }
            if(st != m){
                out.println(-1)
            }
            else{
                out.println(ans-1)
            }
        }

    }
}