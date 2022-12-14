package main
import "fmt"

func main(){
	// your code goes here
	var l, r, ans1, ans2, res int64
	fmt.Scan(&l, &r)
	res = 0;
	for i:=0; i <= 30; i++{
		for j := 0; j <= 20; j++{
			ans1 = 1;
			ans2 = 1;
			for k := 0; k < i; k++{
				ans1 *= 2;
			}
			for k := 0; k < j; k++{
				ans2 *= 3;
			}
			if ans1 * ans2 >= l{
				if ans1 * ans2 <= r{
					res++;
				}
			}
		}
	}
	fmt.Printf("%d", res)
}