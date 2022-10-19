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
    var n int64
    fmt.Fscan(reader, &n)
    ans := 99
    for u := 0; u < 10; u += 5 {
      steps := 0
      m := n
      for m > 0 {
        if int(m%10) != u {
          steps++
          m /= 10
        } else {
          break
        }
      }
      for m > int64(u) {
        if m%25 != 0 {
          m = 10*(m/100) + int64(u)
          steps++
        } else {
          break
        }
      }
      if m != 0 {
        if ans > steps {
          ans = steps
        }
      }
    }
    fmt.Fprint(writer, ans, "\n")
  }
}