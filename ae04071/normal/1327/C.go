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

type Vec struct {
	x int
	y int
}

func PrintDir(n int, ch byte) {
	for i := 0; i < n; i++ {
		fmt.Printf("%c", ch)
	}
}

func main() {
	reader := Reader()
	n, m := reader(), reader()
	fmt.Println( n-1 + m-1 + n*m-1 )
	PrintDir(n-1, 'U')
	PrintDir(m-1, 'L')
	
	for i := 0; i < n; i++ {
		if i%2 == 0 {
			PrintDir(m-1, 'R')
		} else {
			PrintDir(m-1, 'L')
		}
		if i != n-1 {
			PrintDir(1, 'D')
		}
	}
}