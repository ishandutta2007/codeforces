from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
n,x = map(int,input().split())
a = list(map(int,input().split()))

l = [0 for i in range(n+1)]
r = [0 for i in range(n+1)]
pre = [a[0]]
for i in range(1,n):
	pre.append(pre[-1]+a[i])

max_ending_here = 0
max_so_far = 0
for i in range(n):
	max_ending_here += a[i]
	if(max_ending_here < 0):
		max_ending_here = 0
	l[i] = max_ending_here
	
max_ending_here = 0
max_so_far = 0
for i in range(n-1,-1,-1):
	max_ending_here += a[i]
	if(max_ending_here < 0):
		max_ending_here = 0
	r[i] = max_ending_here

rans = lans = 0
for i in range(n):
	rans = max(rans,r[i+1]+pre[i]*x+lans)
	rans = max(rans,l[i])
	lans = max(lans,l[i]-pre[i]*x)
print(rans)