package main

import (
  "fmt"
  "bufio"
  "os"
)

type state struct {
  seen bool
  color bool
  pj int
  pk int
  pl int
}

var dp [41][41][41][41]state

func abs(x int) int {
  if (x < 0) {
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
    var n, A, B int
    fmt.Fscan(reader, &n, &A, &B)
    var s string;
    fmt.Fscan(reader, &s)

    dp[0][0][0][0].seen = true
    for i := 0; i < n; i++ {
      v := int(s[i]-'0')
      for j := 0; j <= i; j++ {
        for k := 0; k < A; k++ {
          for l := 0; l < B; l++ {
            if dp[i][j][k][l].seen {
              dp[i+1][j+1][(10*k+v)%A][l] = state{true, true, j, k, l}
              dp[i+1][j][k][(10*l+v)%B] = state{true, false, j, k, l}
            }
          }
        }
      }
    }

    best := 500
    var bestj int
    for j := 1; j < n; j++ {
      if dp[n][j][0][0].seen && abs(2*j-n) < best {
        bestj = j
        best = abs(2*j-n)
      }
    }

    if best != 500 {
      ans := make([]bool, n)
      sj := bestj
      sk := 0
      sl := 0
      for i := 0; i < n; i++ {
        state := dp[n-i][sj][sk][sl]
        ans[n-1-i] = state.color
        sj, sk, sl = state.pj, state.pk, state.pl
      }
      var z string
      for i := 0; i < n; i++ {
        if ans[i] {
          z += "R"
        } else {
          z += "B"
        }
      }
      fmt.Fprint(writer, z, "\n")
    } else {
      fmt.Fprint(writer, "-1\n")
    }

    for i := 1; i <= n; i++ {
      for j := 0; j <= i; j++ {
        for k := 0; k < A; k++ {
          for l := 0; l < B; l++ {
            dp[i][j][k][l] = state{false, false, 0, 0, 0}
          }
        }
      }
    }
  }
}