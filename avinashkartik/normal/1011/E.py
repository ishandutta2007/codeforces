from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)

n,k = map(int,input().split())
a = list(map(int,input().split()))
g = a[0]%k
for i in range(1,n):
	g = gcd(g,a[i]%k)
ans = [g]
x = (g+g)%k
while(x != g):
	ans.append(x)
	x += g
	x %= k
print(len(ans))
ans.sort()
for i in ans:
	print(i,end = " ")
print()