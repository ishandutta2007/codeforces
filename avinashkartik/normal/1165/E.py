from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
n= int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
b.sort(reverse = True)
ans = 0
mod = 998244353
for i in range(n):
	a[i] = ((n-i)*(i+1)*a[i])
a.sort()
for i in range(n):
	ct = ((b[i]%mod)*(a[i]%mod))%mod
	ans = (ans+ct)%mod
print(ans)