from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
t = int(input())
for y in range(t):
	n = int(input())
	a = list(map(int,input().split()))
	me = 0
	ms = 0
	for i in range(1,n):
		me = max(me+a[i],0)
		ms = max(ms,me)
	me = 0
	for i in range(n-1):
		me = max(me+a[i],0)
		ms = max(ms,me)
	if(ms >= sum(a)):
		print("NO")
	else:
		print("YES")