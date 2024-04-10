package main
import (
	"fmt"
)
import (
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

func main() {
	reader := Reader()
	t := reader()

	for ; t > 0; t-- {
		n := reader()
		var al []int
		king_chk := make([]bool, n + 1)
		for i := 1; i <= n; i++ {
			king_chk[i] = false
		}
		for i := 1; i <= n; i++ {
			k := reader()
			flag := true
			for ; k > 0; k-- {
				j := reader()
				if flag && !king_chk[j] {
					flag = false
					king_chk[j] = true
				}
			}
			if flag {
				al = append(al, i)
			}
		}

		if len(al) > 0 {
			fmt.Println("IMPROVE")
			for i := 1; i <= n; i++ {
				if !king_chk[i] {
					fmt.Printf("%d %d\n", al[0], i)
					break
				}
			}
		} else {
			fmt.Println("OPTIMAL")
		}
	}
}