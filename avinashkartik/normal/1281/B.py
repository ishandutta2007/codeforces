from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
mod = 10**9 + 7

t = int(input())
for y in range(t):
	s,t = input().split()
	s = list(s)
	n = len(s)
	m = len(t)
	key = 1
	pre = [0 for i in range(n)]
	pre[n-1] = n-1
	minn = n-1
	for i in range(n-2,-1,-1):
		if(s[i] < s[minn]):
			minn = i
			pre[i] = i
		else:
			pre[i] = minn
	for i in range(n):
		j = pre[i]
		s[j],s[i] = s[i],s[j]
		s1 = "".join(s)
		if(s1 < t):
			print("".join(s))
			break
		s[j],s[i] = s[i],s[j]
	else:
		s1 = "".join(s)
		if(s1 < t):
			print("".join(s))
		else:
			print("---")