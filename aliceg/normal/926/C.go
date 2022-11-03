package main
import "fmt"
import "os"

func main() {
   var n int
   b := 0
   a := 0
   fmt.Scan(&n)
   var flag bool = false
   for n > 0 {
	n--;
	var m int
	fmt.Scan(&m)
	
	if m > 0 { 
		
		if flag {
			a++
		} else {
			flag = !flag
			if !(a == 0 || b == 0) {
				if a != b {
					fmt.Println("NO")
					os.Exit(0)
				}
				a = 0
			}
			a++
		}
	} else {
		if !flag {
			b++
		} else {
			flag = !flag
			if !(a == 0 || b == 0) {
				if a != b {
					fmt.Println("NO")
					os.Exit(0)
				}
				b = 0
			}
			b++
		}
	} 

   }
   	if !(a == 0 || b == 0) {
		if a != b {
			fmt.Println("NO")
			os.Exit(0)
		}
	}
	fmt.Println("YES")
}