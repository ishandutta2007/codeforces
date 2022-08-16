from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
mod = 1000000009

def power(x, y) : 
    res = 1
    x = x % mod 
  
    while (y > 0) : 
        if ((y & 1) == 1) : 
            res = (res * x) % mod

        y = y >> 1 
        x = (x * x) % mod
          
    return res 

n,m,k = map(int,input().split())
s = n//k
ct = (k-1)*s + n%k
if(ct >= m):
	print(m)
else:
	diff = m - ct
	ans = power(2,diff+1)-2
	ans *= k
	ans %= mod
	ans += ((k-1)*(s-diff))%mod
	ans %= mod
	ans += n%k
	ans %= mod
	print(ans)