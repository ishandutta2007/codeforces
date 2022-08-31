from collections import *
n = int(input())
a, b = [], []
for i in range(n):
	x,y = map(int,input().split())
	a.append(x)
	b.append(y)
if (sum(a) + sum(b))%2 == 1:
	print(-1)
	exit(0)
if(sum(a)%2 == 0 and sum(b)%2 == 0):
	print(0)
	exit(0)
for i in range(n):
	if (a[i]+b[i])%2 == 1:
		print(1)
		break
else:
	print(-1)