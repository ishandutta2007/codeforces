from collections import *
n,q = map(int,input().split())
l = deque(map(int,input().split()))
m = max(l)
a = []
i = 0
while(l[0] != m):
	u,v = l.popleft(),l.popleft()
	a.append([u,v])
	if(u > v):
		l.appendleft(u)
		l.append(v)
	else:
		l.appendleft(v)
		l.append(u)
	i += 1
#print(i)
for j in range(q):
	x = int(input())
	if(x <= i):
		print(a[x-1][0],a[x-1][1])
	else:
		print(m,l[(x-i-1)%(n-1)+1])