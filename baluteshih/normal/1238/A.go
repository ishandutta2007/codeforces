package main
 
import (
	"bufio"
	"fmt"
	"os"
)
 
func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	t := int64(0)
	fmt.Fscanf(in, "%d\n", &t)
	for tt := int64(0); tt < t; tt++ {
		x, y := int64(0), int64(0)
		fmt.Fscanf(in, "%d %d\n", &x, &y)
		if x-y > 1 {
			fmt.Fprintf(out, "YES\n")
		} else {
			fmt.Fprintf(out, "NO\n")
		}
	}
	return
}