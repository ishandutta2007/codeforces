package main
import (
	"fmt"
)
import (
	"bufio"
	"os"
	"io"
)

func ReadInt(line []byte) int {
	var ret = 0
	for i := range line {
		ret = ret * 10 + int(line[i] - '0')
	}
	return ret
}

func Reader() func() int {
	var input []byte
	var idx int
	scanner := bufio.NewReader(os.Stdin)
	return func() int {
		var ret, sign = 0, 1
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
	n := reader()

	for ; n > 0; n-- {
		a := reader()
		if a == 1 {
			fmt.Println(-1)
		} else {
			fmt.Print(5)
			for i := 0; i < a-1; i++ {
				fmt.Print(7)
			}
			fmt.Println()
		}
	}
}