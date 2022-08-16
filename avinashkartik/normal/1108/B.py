from collections import *
from math import *

n = int(input())
a = list(map(int,input().split()))
a.sort()
x, y = 1, a[-1]
d = dict()
for i in range(n-1,-1,-1):
	if a[i] in d:
		x = a[i]
		break
	if(y%a[i] == 0):
		d[a[i]] = 1
	else:
		x = a[i]
		break
print(x,y)