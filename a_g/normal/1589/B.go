package main

import "fmt"

func main() {
  var t int
  fmt.Scanf("%d\n", &t)
  for ; t > 0; t-- {
    var m, n int
    fmt.Scanf("%d %d\n", &m, &n)
    fmt.Printf("%d\n", (m*n+2)/3)
  }
}