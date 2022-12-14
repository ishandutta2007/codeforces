package main

import (
	"bufio"
	"fmt"
	"os"
)

var in *bufio.Reader
var out *bufio.Writer

////////////////////////////////////////////////

func solve() {
	s := ReadString()
	n := len(s)

	w := ReadInt()
	m := ReadInt()

	ps := make([]int, n)
	ps[0] = int(s[0] - '0')
	for i := 1; i < n; i++ {
		ps[i] = (ps[i-1]*10 + int(s[i]-'0')) % 9
	}

	pw := make([]int, n+1)
	pw[0] = 1
	for i := 1; i <= n; i++ {
		pw[i] = (pw[i-1] * 10) % 9
	}

	get := func(l, r int) int {
		ans := ps[r-1]
		if l > 0 {
			ans -= ps[l-1] * pw[r-l]
		}
		return (ans%9 + 9) % 9
	}

	pos := make([]int, 9)
	for i, _ := range pos {
		pos[i] = -1
	}
	pos2 := make([]int, 9)
	copy(pos2, pos)

	for i := 0; i+w <= n; i++ {
		md := get(i, i+w)
		if pos[md] == -1 {
			pos[md] = i
		} else if pos2[md] == -1 {
			pos2[md] = i
		}
	}

	for i := 0; i < m; i++ {
		l := ReadInt()
		l--
		r := ReadInt()
		zal := ReadInt()

		cur := get(l, r)
		ansx := n
		ansy := n
		for x := 0; x < 9; x++ {
			if pos[x] == -1 {
				continue
			}
			if pos2[x] != -1 && (x*cur+x)%9 == zal {
				if pos[x] < ansx || (pos[x] == ansx && pos2[x] < ansy) {
					ansx, ansy = pos[x], pos2[x]
				}
			}
			for y := 0; y < 9; y++ {
				if x == y || pos[y] == -1 || (x*cur+y)%9 != zal {
					continue
				}

				if pos[x] < ansx || (pos[x] == ansx && pos[y] < ansy) {
					ansx, ansy = pos[x], pos[y]
				}
			}
		}
		if ansx == n {
			Println("-1 -1")
		} else {
			Println(ansx+1, ansy+1)
		}
	}
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

func ReadLong() int64 {
	var x int64
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

func ReadString() string {
	var x string
	fmt.Fscan(in, &x)
	return x
}

func Print(a ...any) {
	fmt.Fprint(out, a...)
}

func Println(a ...any) {
	fmt.Fprintln(out, a...)
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

func Abs(x int) int {
	if x < 0 {
		return -x
	} else {
		return x
	}
}