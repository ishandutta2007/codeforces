package main

import "fmt"

func main() {
  var t int
  fmt.Scanf("%d\n", &t)
  for ; t > 0; t-- {
    var u, v int64
    fmt.Scanf("%d %d\n", &u, &v)
    x := -u*u;
    y := v*v;
    fmt.Printf("%d %d\n", x, y)
  }
}