from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
n = int(input())
a = list(map(int,input().split()))
ans = -1
a.sort()
for i in range(n+1):
	l = a[i+n-1] - a[i]
	if(i == 0):
		r = a[-1] - a[n]
	elif(i == n):
		r = a[n-1] - a[0]
	else:
		r = a[-1] - a[0]
	if(ans != -1):
		ans = min(ans,l*r)
	else:
		ans = l*r
print(ans)