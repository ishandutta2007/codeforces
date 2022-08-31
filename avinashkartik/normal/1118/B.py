from collections import *
from math import *

n = int(input())
a = list(map(int,input().split()))
o,e,fo,fe = 0,0,0,0
for i in range(n):
	if(i&1): o += a[i]
	else: e += a[i]
ans = 0
for i in range(n):
	if(i&1):
		o -= a[i]
		x = o+fe
		y = e+fo
		fo += a[i]
	else:
		e -= a[i]
		x = o+fe
		y = e+fo
		fe += a[i]
	if(x == y):
		ans += 1
print(ans)