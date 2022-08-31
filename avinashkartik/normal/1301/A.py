from math import *
import sys
sys.setrecursionlimit(10**9)
t = int(input())
for y in range(t):
	a = input()
	b = input()
	c = input()
	n = len(a)
	for i in range(n):
		if(a[i] == c[i] or b[i] == c[i]): continue
		print("NO")
		break
	else:
		print("YES")