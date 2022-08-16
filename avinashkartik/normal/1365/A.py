from math import *
t = int(input())
for y in range(t):
	n,m = map(int,input().split())
	a = []
	for i in range(n):
		a.append(list(map(int,input().split())))
	r,c = 0,0
	for i in range(n):
		ct = 0
		for j in range(m):
			if(a[i][j] == 0):
				ct += 1
		if(ct == m):
			r += 1
	for i in range(m):
		ct = 0
		for j in range(n):
			if(a[j][i] == 0):
				ct += 1
		if(ct == n):
			c += 1
	x = min(r,c)
	if(x&1):
		print("Ashish")
	else:
		print("Vivek")