from math import *
t = int(input())
for y in range(t):
	x,n,m = map(int,input().split())
	while(n > 0):
		if(x < 20): break
		x //= 2
		x += 10
		n -= 1
	while(m > 0):
		x -= 10
		m -= 1
	if(x > 0):
		print("NO")
	else:
		print("YES")