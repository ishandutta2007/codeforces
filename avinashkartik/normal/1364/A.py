from collections import *
from math import *

t = int(input())
for y in range(t):
	n,x = list(map(int,input().split()))
	a = list(map(int,input().split()))
	s = sum(a)
	if(s%x != 0):
		print(n)
		continue
	s = -1
	for i in range(n):
		if(a[i]%x != 0):
			s = i+1
			break
	if(s == -1):
		print(-1)
		continue
	e = -1
	for i in range(n-1,-1,-1):
		if(a[i]%x != 0):
			e = n-i
			break
	print(n-min(s,e))