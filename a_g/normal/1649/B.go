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
		mx := 0
		sum := int64(0)
		for i := 0; i < n; i++ {
			fmt.Fscan(reader, &a[i])
			if a[i] > mx {
				mx = a[i]
			}
			sum += int64(a[i])
		}
		if mx == 0 {
			fmt.Fprint(writer, "0\n")
			continue
		}
		sum -= int64(mx)
		if int64(mx) > sum {
			fmt.Fprintf(writer, "%d\n", int64(mx)-sum)
			continue
		}
		fmt.Fprint(writer, "1\n")
	}
}