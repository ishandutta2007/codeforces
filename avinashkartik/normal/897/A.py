from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)

n,m = map(int,input().split())
s = list(input())
for i in range(m):
	a = list(input().split())
	l = int(a[0])
	r = int(a[1])
	c1 = a[2]
	c2 = a[3]
	for j in range(l-1,r):
		if(s[j] == c1):
			s[j] = c2
print("".join(s))