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
		var n int
		fmt.Fscan(reader, &n)
		a := make([]int, n)
		for i := 0; i < n; i++ {
			fmt.Fscan(reader, &a[i])
		}
		l := 0
		r := n-1
		for ; l < n-1 && a[l+1] == 1; l++ {}
		for ; r > 0 && a[r-1] == 1; r-- {}
		ans := r-l
		if ans < 0 {
			ans = 0
		}
		fmt.Fprintf(writer, "%d\n", ans)
  }
}