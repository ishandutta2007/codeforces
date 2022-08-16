from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)

mod = 10**9 + 7
n = int(input())
a = list(input())
ans = []
for i in range(n-1):
	if(a[i] == 'B'):
		continue
	else:
		a[i] = 'B'
		if(a[i+1] == 'B'): a[i+1] = 'W'
		else: a[i+1] = 'B'
		ans.append(i+1)
if(a[-1] == 'W' and n%2 == 0):
	print(-1)
elif(a[-1] == 'W'):
		print(len(ans)+n//2)
		for i in ans:
			print(i,end = " ")
		for i in range(1,n,2):
			print(i,end = " ")
else:
	print(len(ans))
	for i in ans:
		print(i,end = " ")