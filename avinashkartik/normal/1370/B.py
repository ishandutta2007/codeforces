from collections import *
from math import *

t = int(input())
for y in range(t):
	n = int(input())
	a = list(map(int,input().split()))
	o = []
	e = []
	for i in range(2*n):
		if(a[i]&1):
			o.append(i+1)
		else:
			e.append(i+1)
	ans = []
	N = len(o)
	M = len(e)
	while(N > 1):
		ans.append([o[-1],o[-2]])
		o.pop()
		o.pop()
		N -= 2
	while(M > 1):
		ans.append([e[-1],e[-2]])
		e.pop()
		e.pop()
		M -= 2
	for i in range(n-1):
		print(*ans[i])