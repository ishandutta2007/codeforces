package main 

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	if n%2==1 {fmt.Print(7)}
	if n%2==0 {fmt.Print(1)}
	for i := 0; i < n/2-1; i++ {fmt.Print(1)}
}