from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)

t = int(input())
for y in range(t):
	n = int(input())
	a = list(map(int,input().split()))
	g = s = b = 0
	i = 0
	while(i < n-1 and a[i+1] == a[i]):
		i += 1
	i += 1
	g = i
	while(i < n-1 and a[i+1] == a[i]):
		i += 1
		s += 1
	i += 1
	s += 1
	while(i <= n//2):
		j = 0
		while(i < n-1 and a[i+1] == a[i]):
			i += 1
			j += 1
		i += 1
		if(i <= n//2):
			if(s <= g):
				s += j+1
			else:
				b += j+1
		else:
			break
	if(g+b+s <= n//2 and g*b*s > 0 and g < b and g < s):
		print(g,s,b)
	else:
		print(0,0,0)