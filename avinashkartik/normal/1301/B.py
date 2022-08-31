from math import *

t = int(input())
for y in range(t):
	n = int(input())
	a = list(map(int,input().split()))
	if(a.count(-1) == n):
		print(0,0)
	else:
		m1 = 1e9+8
		m2 = -2
		for i in range(n):
			if(a[i] != -1):
				if(i != n-1 and a[i+1] == -1):
					m2 = max(a[i],m2)
					m1 = min(a[i],m1)
				if(i != 0 and a[i-1] == -1):
					m2 = max(a[i],m2)
					m1 = min(a[i],m1)
		x = (m1+m2)//2
		for i in range(n):
			if(a[i] == -1):
				a[i] = x
		ans = 0
		for i in range(1,n):
			ans = max(ans,abs(a[i]-a[i-1]))
		print(ans,x)