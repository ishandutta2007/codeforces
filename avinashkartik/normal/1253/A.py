from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
t = int(input())
for y in range(t):
	n = int(input())
	a = list(map(int,input().split()))
	b = list(map(int,input().split()))
	d = [0 for i in range(n)]
	for i in range(n):
		if(a[i] != b[i]):
			d[i] = a[i]-b[i]
	flag = 0
	ch = 0
	ans = "YES"
	last = 0
	#print(d)
	for i in range(n):
		if(flag == 1 and d[i] != 0):
			if(d[i] != ch or last != i-1):
				ans = "NO"
				break
			last = i
		elif(d[i] != 0):
			flag = 1
			ch = d[i]
			last = i
			if(ch > 0):
				ans = "NO"
				break
	print(ans)