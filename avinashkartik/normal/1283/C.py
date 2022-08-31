from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
n = int(input())
a = list(map(int,input().split()))
b = [0 for i in range(n+1)]
for i in a:
	b[i] = 1
ans = []
for i in range(1,n+1):
	if(b[i] == 0): ans.append(i)
j = 0
prev = -1
m = len(ans)
for i in range(n-1,-1,-1):
	if(a[i] == 0):
		if(ans[j] == i+1):
			if(j+1 == m):
				ans[j-1],ans[j] = ans[j],ans[j-1]
				a[prev] = ans[j-1]
			else:
				ans[j+1],ans[j] = ans[j],ans[j+1]	
		a[i] = ans[j]
		j += 1
		prev = i
for i in a:
	print(i,end = " ")
print()