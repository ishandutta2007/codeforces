from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
t = int(input())
for y in range(t):
	n,p,k = map(int,input().split())
	a = list(map(int,input().split()))
	a.sort()
	pre = [a[0]]
	for i in range(1,k):
		pre.append(a[i] + pre[-1])
	ct = 0
	for j in range(k-1,2*k-1):
		ct1 = 0
		p1 = p
		for i in range(j,n,k):
			if(a[i] <= p1):
				ct1 += k
				p1 -= a[i]
		l = 0
		r = j-k
		while(l <= r):
			mid = (l+r)//2
			if(pre[mid] <= p1):
				l = mid + 1
			else:
				r = mid - 1
		ct = max(ct,ct1+l)
	print(ct)