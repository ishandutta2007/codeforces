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

	for i := 0; i < t; i++ {
		n, k := int64(reader()), int64(reader())
		if (n%2==0 && k%2==0 && n >= k*k) || (n%2==1 && k%2==1 && n >= k*k) {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
	}
}