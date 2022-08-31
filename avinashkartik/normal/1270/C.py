from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
t = int(input())
for y in range(t):
	n = int(input())
	a = list(map(int,input().split()))
	s = x = 0
	for i in a:
		s += i
		x ^= i
	print(2)
	print(x,s+x)