package main
import (
	. "fmt"
	"bufio"
	"os"
	"io"
)

func Reader() func() int {
	var input []byte
	var idx int = 0
	scanner := bufio.NewReader(os.Stdin)
	return func() int {
		var ret, sign int = 0, 1
		for flag := true; flag; {
			for ; idx < len(input); idx++ {
				if (input[idx] >= '0' && input[idx] <= '9') || input[idx] == '-' {
					if input[idx] == '-' {
						sign = -1
						idx += 1
					}
					flag = false
					break
				}
			}
			if !flag {
				break
			}

			var err error
			input, _, err = scanner.ReadLine()
			idx = 0
			if err == io.EOF {
				return -1
			}
		}
		for ; idx < len(input) && input[idx]>='0' && input[idx]<='9'; idx++ {
			ret = ret * 10 + int(input[idx] -'0');
		}
		return ret * sign
	}
}

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
	//reader := Reader()
	var t, n int
	in, out := bufio.NewReader(os.Stdin), bufio.NewWriter(os.Stdout)
	defer out.Flush()
	Fscan(in, &t)
	primes := GetPrimeList(200000)
	for ; t > 0; t-- {
		Fscan(in, &n)
		adj := make([]int, n+1)
		colors := make([]int, n+1)
		vis := make([]bool, n+1)
		for i := range vis {
			vis[i] = false
		}
		for i := 1; i <= n; i++ {
			Fscan(in, &adj[i])
		}
		for i := 1; i <= n; i++ {
			Fscan(in, &colors[i])
		}

		ans := n
		for i := 1; i <= n; i++ {
			if !vis[i] {
				var cycle_colors []int
				l := dfs(i, &adj, &vis, &colors, &cycle_colors)
				tmp := GetLeast(l, &primes, &cycle_colors)
				if ans > tmp {
					ans = tmp
				}
			}
		}
		Fprintln(out, ans)
	}
}