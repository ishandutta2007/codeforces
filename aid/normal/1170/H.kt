import java.util.*
import java.lang.Math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main(){

  fun solve() : String {
    var n = readInt()
    var a = readInts().toMutableList()
    var mp = sortedMapOf<Int, Int>()
    for (x in a) {
      if (!mp.containsKey(x)) {
        mp[x] = 0
      }
      mp[x] = mp.getValue(x) + 1
    }
    var mx = 0
    var who = -1
    for (p in mp) {
      if (p.value > mx) {
        mx = p.value
        who = p.key
      }
    }
    while (mx > n - mx + 1) {
      mx--
      n--
    }
    if (mx > n - mx && who != mp.lastKey() && who != mp.firstKey()) {
      mx--
      n--
    }
    mp[who] = mx
    a = mutableListOf()
    for (p in mp) {
      for (i in 1..(p.value)) {
        a.add(p.key)
      }
    }
    var ans = mutableListOf<Int>()
    if (mx > n - mx) {
      if (who == mp.firstKey()) {
        for (i in mx..(n - 1)) {
          ans.add(who)
          ans.add(a[i])
        }
        ans.add(who)
      } else {
        for (i in 0..(mx - 2)) {
          ans.add(who)
          ans.add(a[i])
        }
        ans.add(who)
      }
    } else {
      var k = n / 2
      for (i in 0..(k - 1)) {
        ans.add(a[i + k])
        ans.add(a[i])
      }
      if (n % 2 == 1) {
        ans.add(a.last())
      }
    }
    return ans.size.toString() + "\n" + ans.joinToString(" ")
  }

  var t = readInt()
  println((1..t).joinToString("\n") { solve() })
}