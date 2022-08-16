from collections import *
n = int(input())
a = list(map(int,input().split()))
m = 0
p = 0
for i in range(n-2,-1,-1):
	p += a[i]
	m = min(m,p)
ans = [0 for i in range(n)]
ans[-1] = n+m
p = 0
for i in range(n-2,-1,-1):
	p += a[i]
	ans[i] = ans[-1]-p
vis = [0 for i in range(n+1)]
for i in range(n):
	if(ans[i] < 1 or ans[i] > n):
		continue
	vis[ans[i]] = 1
if(sum(vis) == n):
	print(*ans)
else:
	print(-1)