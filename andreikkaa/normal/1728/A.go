package main

import (
	"fmt"
	"os"
)

func solve() {
	n := readInt()

	mx := 0
	ans := 0
	for i := 0; i < n; i++ {
		x := readInt()
		if x > mx {
			mx = x
			ans = i + 1
		}
	}

	fmt.Println(ans)
}

func main() {
	t := readInt()

	for i := 0; i < t; i++ {
		solve()
	}
}

func readInt() int {
	var x int
	fmt.Fscan(os.Stdin, &x)
	return x
}