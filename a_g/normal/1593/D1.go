package main

import (
  "fmt"
  "bufio"
  "os"
)

func gcd(x int, y int) int {
  if x < 0 {
    x = -x
  }
  if y < 0 {
    y = -y
  }
  if x < y {
    return gcd(y, x)
  }
  if y == 0 {
    return x
  }
  return gcd(y, x%y)
}

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
    for i := 0; i < n; i++ {
      fmt.Fscan(reader, &arr[i])
    }
    ans := 0
    for i := 0; i < n-1; i++ {
      ans = gcd(ans, arr[i+1]-arr[i])
    }
    if ans == 0 {
      ans = -1
    }
    fmt.Fprint(writer, ans, "\n")
  }
}