from math import *
h,n = map(int,input().split())
a = list(map(int,input().split()))
s = sum(a)
p = 0
ans = 1e18
if(s >= 0):
	for i in range(n):
		p -= a[i]
		if(p >= h):
			print(i+1)
			break
	else:
		print(-1)
else:
	s = -s
	for i in range(n):
		p -= a[i]
		if(p >= h):
			ans = min(ans,i+1)
		else:
			x = n*ceil((h-p)/s)+i+1
			ans = min(ans,x)
	print(ans)