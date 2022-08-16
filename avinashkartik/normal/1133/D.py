from collections import *
from math import *
n = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
d = dict()
d[0] = 0
ct = 0
for i in range(n):
	if(a[i] == 0):
		if(b[i] == 0):
			ct += 1
		continue
	if(b[i] == 0):
		d[0] += 1
		continue
	f = (b[i] < 0)^(a[i] < 0)
	g = gcd(b[i],a[i])
	x = (abs(b[i])/g,abs(a[i])/g,f)
	if(x not in d): d[x] = 0
	d[x] += 1
print(max(d.values())+ct)