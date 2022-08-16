from math import *
from collections import *
n = int(input())
a = list(map(int,input().split()))
ans = 0
fres = []
for i in range(n):
	s = a[i]
	prev = a[i]
	res = []
	for j in range(i-1,-1,-1):
		prev = min(a[j],prev)
		s += prev
		res.append(prev)
	prev = a[i]
	res = res[::-1]
	res.append(a[i])
	for j in range(i+1,n):
		prev = min(a[j],prev)
		s += prev
		res.append(prev) 
	if(s > ans):
		ans = s
		fres = res[::]
for i in fres:
	print(i,end = " ")