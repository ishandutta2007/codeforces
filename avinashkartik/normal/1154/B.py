from math import *
n = int(input())
a = list(map(int,input().split()))
mn = min(a)
mx = max(a)
if (mx-mn)%2 == 1: d = mx-mn
else: d = (mx-mn)//2
mid = mn + d
for i in range(n):
	if(a[i] < mid):
		a[i] += d
	if(a[i] > mid):
		a[i] -= d
	if(a[i] != mid):
		print(-1)
		break
else:
	print(d)