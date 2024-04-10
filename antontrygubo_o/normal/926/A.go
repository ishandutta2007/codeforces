package main

import (
        "fmt"
        "sort"
        )

var a [100000]int
var l, r int
var ans, ans1, j int64

func main() {
	fmt.Scanf("%d %d", &l, &r)
	num:=0
	ans=1
    for i:=0; i<=30; i++{
        a[num]=int(ans)
        num++
        ans1=ans
        for (ans1<int64(2000000000)){
            ans1=ans1*int64(3)
            if (ans1<int64(2000000000)){
              a[num]=int(ans1)
              num++
            }
        }
        ans*=int64(2)
    }
    sort.Ints(a[:])
    i:=0
    for i<100000 && a[i]<l{
        i++
    }
    j:=0
    for j<100000 && a[j]<=r{
        j++
    }
    if (j>=i){
      fmt.Printf("%d", j-i)
        
    } else{
      fmt.Printf("%d", 0)
    }
}