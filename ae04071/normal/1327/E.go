package main
import (
	. "fmt"
	"bufio"
	"os"
)

func GetPrimeList(n int) []int {
	var plist []int
	chk := make([]bool, n+1)
	for i := 2; i <= n; i++ { chk[i] = false }
	for i := 2; i <= n; i++ {
		if !chk[i] {
			plist = append(plist, i)
			for j := int64(i) * int64(i); j <= int64(n); j += int64(i) {
				chk[j] = true
			}
		}
	}
	return plist
}

type Factor struct {
	val int
	size int
}

func GetPrimeFactors(n int, primes *[]int) []Factor {
	var factors []Factor
	for i := 0; i < len(*primes) && int64((*primes)[i]) * int64((*primes)[i]) <= int64(n); i++ {
		if n % (*primes)[i] == 0 {
			size := 0
			for ; n % (*primes)[i] == 0; {
				n /= (*primes)[i]
				size++
			}
			factors = append(factors, Factor{(*primes)[i], size})
		}
	}
	if n != 1 {
		factors = append(factors, Factor{n, 1})
	}
	return factors
}

func GenDivisor(idx, val int, factors *[]Factor, divisor *[]int) {
	if idx == len(*factors) {
		*divisor = append(*divisor, val)
		return
	}

	for j := 0; j <= (*factors)[idx].size; j++ {
		GenDivisor(idx+1, val, factors, divisor)
		val *= (*factors)[idx].val
	}
}

func GetLeast(n int, primes *[]int, colors *[]int) int {
	ret := n
	factors := GetPrimeFactors(n, primes)
	var divisors []int
	GenDivisor(0, 1, &factors, &divisors)
	for _, div := range divisors {
		cs := make([]int, div)
		for i := range cs {
			cs[i] = 0
		}
		for i := 0; i < n; i++ {
			if cs[i%div] == 0 {
				cs[i%div] = (*colors)[i]
			} else if cs[i%div] != (*colors)[i] {
				cs[i%div] = -1
			}
		}
		for _, state := range cs {
			if state != -1 && ret > div {
				ret = div
			}
		}
	}
	return ret
}

func dfs(cur int, adj *[]int, vis *[]bool, colors, arr_col *[]int) int {
	if (*vis)[cur] {
		return 0
	}
	*arr_col = append(*arr_col, (*colors)[cur])
	(*vis)[cur] = true
	return dfs((*adj)[cur], adj, vis, colors, arr_col) + 1
}

func main() {
	in, out := bufio.NewReader(os.Stdin), bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var n int64
	Fscan(in, &n)

	ans := make([]int64, n+1)
	ans[n] = 10

	var tf, MOD int64 = 1, 998244353
	for l := n-1; l > 0; l-- {
		a, b := int64(9*9), int64(180)
		ans[l] = tf * ((n-int64(l)-int64(1))*a + b) % MOD;
		tf = tf * 10 % MOD;
	}
	for i := int64(1); i<=n; i++ {
		Fprintf(out, "%d ", ans[i])
	}
}