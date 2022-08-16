from collections import *
from math import *
n,k = map(int,input().split())
a = list(map(int,input().split()))
d = dict()
for i in range(k): d[i] = 0
for i in range(n):
	d[a[i]%k] += 1
ans = 0
for i in range(k):
	if(i == 0 or i == k/2):
		ans += (d[i]//2)*2
	else:
		ans += min(d[i],d[k-i])
print(ans)