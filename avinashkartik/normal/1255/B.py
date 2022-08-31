from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
t = int(input())
for i in range(t):
	n,m = map(int,input().split())
	a = list(map(int,input().split()))
	s = sum(a)*2
	for i in range(n):
		a[i] = [a[i],i+1]
	if(m < n or n == 2):
		print(-1)
		continue
	a.sort()
	s += (m-n)*(a[0][0] + a[1][0])
	print(s)
	for i in range(1,n):
		print(i,i+1)
	print(n,1)
	for i in range(m-n):
		print(a[0][1],a[1][0])