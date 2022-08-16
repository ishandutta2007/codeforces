from math import *

te = int(input())
for y in range(te):
	n,m = map(int,input().split())
	a = []
	for i in range(n):
		a.append(list(map(int,input().split())))
	a.sort()
	l = []
	f = 0
	L = m - a[0][0]
	R = m + a[0][0]
	for i in range(n):
		if(a[i][2] < L or a[i][1] > R):
			f = 1
		else:
			R = min(R,a[i][2])
			L = max(L,a[i][1])
		if(i != n-1):
			L = L - a[i+1][0] + a[i][0]
			R = R + a[i+1][0] - a[i][0]
	if(f == 0):
		print("YES")
	else:
		print("NO")