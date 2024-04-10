package main

import (
  "fmt"
  "bufio"
  "os"
)

func max(x int, y int) int {
  if x > y {
    return x
  }
  return y
}

func main() {
  reader := bufio.NewReader(os.Stdin)
  writer := bufio.NewWriter(os.Stdout)
  defer writer.Flush()

  var t int
  fmt.Fscan(reader, &t)
  for ; t > 0; t-- {
    var a, b, c int
    fmt.Fscan(reader, &a, &b, &c)
    fmt.Fprintf(writer, "%d %d %d\n", max(0, max(b+1, c+1)-a), max(0, max(c+1, a+1)-b), max(0, max(a+1, b+1)-c))
  }
}