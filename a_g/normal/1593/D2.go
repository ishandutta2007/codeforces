package main

import (
  "fmt"
  "bufio"
  "os"
)

func main() {
  reader := bufio.NewReader(os.Stdin)
  writer := bufio.NewWriter(os.Stdout)
  defer writer.Flush()

  var t int
  fmt.Fscan(reader, &t)
  for ; t > 0; t-- {
    var n int
    fmt.Fscan(reader, &n)
    arr := make([]int, n)
    m := make(map[int]int)
    z := false
    for i := 0; i < n; i++ {
      fmt.Fscan(reader, &arr[i])
      m[arr[i]]++
      if m[arr[i]] >= n/2 {
        z = true
      }
    }
    if z {
      fmt.Fprint(writer, "-1\n")
      continue
    }

    ans := 1
    check := func (k int) {
      if k <= ans {
        return
      }
      freqs := make(map[int]int)
      for i := 0; i < n; i++ {
        rem := arr[i] % k
        if rem < 0 {
          rem += k
        }
        freqs[rem]++
        if freqs[rem] >= n/2 {
          ans = k
          return
        }
      }
      return
    }

    for i := 0; i < n; i++ {
      for j := 0; j < n; j++ {
        d := arr[i]-arr[j]
        if (d < 0) {
          d = -d
        }
        if (d <= ans) {
          continue
        }
        for k := 1; k*k <= d; k++ {
          if d % k == 0 {
            check(k)
            check(d/k)
          }
        }
      }
    }

    fmt.Fprint(writer, ans, "\n")
  }
}