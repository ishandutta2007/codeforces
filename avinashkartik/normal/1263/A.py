from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)

t = int(input())
for y in range(t):
	r,g,b = map(int,input().split())
	m = max(r,g,b)
	if(r + g + b - m >= m):
		ans = (r+g+b)//2
	else:
		ans = r+g+b - m
	print(ans)