from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
t = int(input())
for y in range(t):
	n,p,k = map(int,input().split())
	a = list(map(int,input().split()))
	a.sort()
	ct = ct1 = 0
	p1 = p
	for i in range(2,n,2):
		if(a[i] <= p):
			ct += 2
			p -= a[i]
	if(ct == 0 and a[1] <= p): ct = 2
	elif(a[0] <= p): ct += 1 
	for i in range(1,n,2):
		if(a[i] <= p1):
			ct1 += 2
			p1 -= a[i]
	print(max(ct,ct1))