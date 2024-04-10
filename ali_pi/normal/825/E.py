n,m=map(int,raw_input().split())
d=[0]*n
e=[[] for i in range(n)]
for i in range(m):
	u,v=map(int,raw_input().split())
	u-=1
	v-=1
	d[u]+=1
	e[v].append(u)
from heapq import heappush, heappop
pq=[]
for i in range(n):
	if d[i]==0:
		heappush(pq,-i)
ind=n
ans=[0]*n
while(pq):
	u=-heappop(pq)
	ans[u]=ind
	ind-=1
	for v in e[u]:
		d[v]-=1
		if d[v]==0:
			heappush(pq,-v)
print(' '.join(str(x) for x in ans))