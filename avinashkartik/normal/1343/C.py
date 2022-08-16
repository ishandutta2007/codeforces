from math import *
test = int(input())
for test_case in range(test):
	n = int(input())
	a = list(map(int,input().split()))
	if(a[0] > 0):
		f = 1
	else:
		f = 0
	i = 0
	ans = 0
	while(i < n):
		m = a[i]
		if(f == 1):
			while(i < n and a[i] > 0):
				m = max(m,a[i])
				i += 1
		else:
			while(i < n and a[i] < 0):
				m = max(m,a[i])
				i += 1
		f = f^1
		#print(m)
		ans += m
	print(ans)