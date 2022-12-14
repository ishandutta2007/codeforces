package main

import (
	"fmt"
	"os"
)

func solve() {
	n := readInt()
	if n%2 == 0 {
		for i := 1; i+2 <= n; i += 2 {
			fmt.Print(i+1, i, " ")
		}
		fmt.Println(n-1, n)
	} else {
		fmt.Print("1 2 3 ")
		for i := 4; i+2 < n; i += 2 {
			fmt.Print(i+1, i, " ")
		}
		fmt.Println(n-1, n)
	}
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

func iota(a []int, start int) {
	for i := 0; i < len(a); i++ {
		a[i] = start
		start++
	}
}

func next_permutation(a []int) bool {
	n := len(a)
	pos := n - 2
	for ; pos >= 0; pos-- {
		if a[pos] < a[pos+1] {
			break
		}
	}
	if pos == -1 {
		return false
	}
	for i := n - 1; i >= 0; i-- {
		if a[i] > a[pos] {
			a[i], a[pos] = a[pos], a[i]
			reverse(a[pos+1 : n])
			break
		}
	}
	return true
}

func reverse(a []int) {
	n := len(a)
	for i := 0; i < n/2; i++ {
		a[i], a[n-i-1] = a[n-i-1], a[i]
	}
}