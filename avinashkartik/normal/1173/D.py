from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)

mod = 998244353
n = int(input())
a = [0 for i in range(n+1)]
ans = n
for i in range(n-1):
	u,v = map(int,input().split())
	a[u] += 1
	a[v] += 1
	ans *= a[u]
	ans %= mod
	ans *= a[v]
	ans %= mod
print(ans%mod)