from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
mod = 10**9 + 7

t = int(input())
for y in range(t):
	s = input()
	h = input()
	key = 0
	n = len(h)
	m = len(s)
	c = Counter(s)
	for i in range(n):
		if Counter(h[i:i+m]) == c:
			key = 1
			break
	if(key == 1):
		print("YES")
	else:
		print("NO")