package main

import (
  "fmt"
  "bufio"
  "os"
  "sort"
)

func main() {
  reader := bufio.NewReader(os.Stdin)
  writer := bufio.NewWriter(os.Stdout)
  defer writer.Flush()

  var t int
  for fmt.Fscan(reader, &t); t > 0; t-- {
    var n, k int
    fmt.Fscan(reader, &n, &k)
    arr := make([]int, k)
    for i := 0; i < k; i++ {
      fmt.Fscan(reader, &arr[i])
    }
    sort.Ints(arr)
    d := 0
    ans := 0
    for i := k-1; i >= 0; i-- {
      if arr[i] <= d {
        break
      }
      ans++
      d += (n-arr[i])
    }
    fmt.Fprint(writer, ans, "\n")
  }
}