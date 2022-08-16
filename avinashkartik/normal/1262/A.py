from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
t = int(input())
for y in range(t):
	n = int(input())
	L = []
	R = []
	for i in range(n):
		l1,r1 = map(int,input().split())
		L.append(l1)
		R.append(r1)
	m1 = max(L)
	m2 = min(R)
	ct = max(0,m1-m2)
	print(ct)