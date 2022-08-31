from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
n = int(input())
a = list(map(int,input().split()))
l = 0
d = dict()
while(l < n):
	if(a[l] not in d):
		d[a[l]] = 1
	else:
		break
	l += 1
ans = 10**4
for j in range(l+1):
	r = n-1
	d = dict()
	for i in range(j):
		d[a[i]] = 1
	while(r > j):
		if(a[r] not in d):
			d[a[r]] = 1
		else:
			break
		r -= 1
	ans = min(r-j+1,ans)
	#print(j,r)
print(ans)