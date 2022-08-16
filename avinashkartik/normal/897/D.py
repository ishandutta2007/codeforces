from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)

n,m,c = map(int,input().split())
l = 0
r = n-1
ans = [0 for i in range(n)]
while(l <= r):
	x = int(input())
	if(x <= c/2):
		i = 0
		while(i < l and ans[i] <= x):
			i += 1
		ans[i] = x
		print(i+1)
		sys.stdout.flush()
		if(i == l):
			l += 1
	else:
		i = n-1
		while(i > r and ans[i] >= x):
			i -= 1
		ans[i] = x
		print(i+1)
		sys.stdout.flush()
		if(i == r):
			r -= 1