from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
n,k = map(int,input().split())
a = list(map(int,input().split()))
l = [k+1 for i in range(n+1)]
r = [-1 for i in range(n+1)]
for i in range(k):
	if(l[a[i]] == k+1):
		l[a[i]] = i
	r[a[i]] = i
ct = 0
for i in range(1,n):
	if(r[i] < l[i+1]):
		ct += 1;
for i in range(2,n+1):
	if(r[i] < l[i-1]):
		ct += 1;
ct += r.count(-1)-1
print(ct)