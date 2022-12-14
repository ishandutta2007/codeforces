package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var in *bufio.Reader
var out *bufio.Writer

func solve() {
	n := ReadInt()
	a := ReadInts(n)
	b := ReadInts(n)

	a1, c1 := f(a)
	a2, c2 := f(b)

	eq := func(a []int, pos int, val int) int {
		x := pos
		for ; pos < len(a) && a[pos] == val; pos++ {
		}
		return pos - x
	}

	ans := 0
	for p1, p2 := 0, 0; p1 < len(a1) || p2 < len(a2); {
		mx := 0
		if p1 < len(a1) {
			mx = a1[p1]
		}
		if p2 < len(a2) && (p1 == len(a1) || a2[p2] > a1[p1]) {
			mx = a2[p2]
		}
		l1 := eq(a1, p1, mx)
		l2 := eq(a2, p2, mx)
		p1 += l1
		p2 += l2
		mn := Min(l1, l2)
		l1 -= mn
		l2 -= mn
		c1[ff(mx)] += l1
		c2[ff(mx)] += l2
		ans += l1 + l2
	}

	for i := 9; i >= 1; i-- {
		cnt := Min(c1[i], c2[i])
		c1[i] -= cnt
		c2[i] -= cnt
		c1[1] += c1[i]
		c2[1] += c2[i]
		ans += c1[i] + c2[i]
	}
	Println(ans)
}

func f(a []int) ([]int, []int) {
	c := make([]int, 10)
	for _, i := range a {
		if i < 10 {
			c[i]++
		}
	}

	a = RemoveIf(a, func(x int) bool { return x < 10 })
	sort.Ints(a)
	Reverse(a)
	return a, c
}

func ff(x int) int {
	ans := 0
	for ; x > 0; x /= 10 {
		ans += 1
	}
	return ans
}

func main() {
	in = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
	defer out.Flush()

	t := 1
	t = ReadInt()

	for i := 0; i < t; i++ {
		solve()
	}
}

func ReadInt() int {
	var x int
	fmt.Fscan(in, &x)
	return x
}

func ReadInts(n int) []int {
	a := make([]int, n)
	for i, _ := range a {
		a[i] = ReadInt()
	}
	return a
}

func Print(a ...any) {
	fmt.Print(a...)
}

func Println(a ...any) {
	fmt.Println(a...)
}

type IntPair struct {
	x int
	y int
}

func Iota(a []int, start int) {
	for i := 0; i < len(a); i++ {
		a[i] = start
		start++
	}
}

func NextPermutation(a []int) bool {
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
			Reverse(a[pos+1 : n])
			break
		}
	}
	return true
}

func Reverse(a []int) {
	n := len(a)
	for i := 0; i < n/2; i++ {
		a[i], a[n-i-1] = a[n-i-1], a[i]
	}
}

func RemoveIf(a []int, cond func(int) bool) []int {
	n := len(a)
	pos := 0
	for i := 0; i < n; i++ {
		if !cond(a[i]) {
			a[pos] = a[i]
			pos++
		}
	}
	return a[0:pos]
}

func Min(a int, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}

func Max(a int, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}