package main

import (
  "fmt"
  "bufio"
  "os"
)

func abs(x int) int {
  if x < 0 {
    return -x
  }
  return x
}

func main() {
  reader := bufio.NewReader(os.Stdin)
  writer := bufio.NewWriter(os.Stdout)
  defer writer.Flush()

  var t int
  for fmt.Fscan(reader, &t); t > 0; t-- {
    var s string
    fmt.Fscan(reader, &s)
    n := len(s)
    pref := make([]int, n+1)
    pref[0] = 0;
    for i:= 0; i < n; i++ {
      pref[i+1] = pref[i]
      if s[i] == '[' || s[i] == ']' {
        if i&1 > 0 {
          pref[i+1]++
        } else {
          pref[i+1]--
        }
      }
    }
    var q int
    fmt.Fscan(reader, &q)
    for ; q > 0; q-- {
      var l, r int
      fmt.Fscan(reader, &l, &r)
      fmt.Fprint(writer, abs(pref[r]-pref[l-1]), "\n")
    }
  }
}