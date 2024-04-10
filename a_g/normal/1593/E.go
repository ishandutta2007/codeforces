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
  for fmt.Fscan(reader, &t); t > 0; t-- {
    var n, k int
    fmt.Fscan(reader, &n, &k)
    adj := make([][]int, n+1)
    degs := make([]int, n+1)
    done := make([]bool, n+1)
    time := make([]int, n+1)
    for i := 0; i < n-1; i++ {
      var u, v int
      fmt.Fscan(reader, &u, &v)
      adj[u] = append(adj[u], v)
      adj[v] = append(adj[v], u)
      degs[u]++
      degs[v]++
    }

    var queue []int
    for i := 1; i <= n; i++ {
      if degs[i] == 1 {
        queue = append(queue, i)
        time[i] = 1;
      }
    }
    j := 0
    for ; j < len(queue); j++ {
      v := queue[j]
      done[v] = true
      for _, u := range adj[v] {
        if !done[u] {
          degs[u]--
          if degs[u] == 1 {
            time[u] = time[v] + 1
            queue = append(queue, u)
          }
        }
      }
    }

    ans := 0
    for i := 1; i <= n; i++ {
      if time[i] > k {
        ans++
      }
    }
    fmt.Fprint(writer, ans, "\n")
  }
}