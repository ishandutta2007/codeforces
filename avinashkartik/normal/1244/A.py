from math import *
q = int(input())
for y in range(q):
	a,b,c,d,n = map(int,input().split())
	m1 = ceil(a/c)
	m2 = ceil(b/d)
	if(m1+m2 <= n):
		print(m1,m2)
	else:print(-1)