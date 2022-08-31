from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)

l = []
ct = 0
for i in range(1,10**5+1):
	s = str(i)
	l.append(s+s[::-1])

n,k = map(int,input().split())
ans = 0
for i in range(n):
	ans += int(l[i])
	ans %= k
print(ans)