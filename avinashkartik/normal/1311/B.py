from math import *
from collections import *
t = int(input())
for y in range(t):
	n,m = map(int,input().split())
	a = list(map(int,input().split()))
	p = list(map(int,input().split()))
	p.sort()
	ans = a[:p[0]-1]
	i = 0
	while(i < m):
		st = i
		while(i < m-1 and p[i]+1 == p[i+1]):
			i += 1
		#print(i,st,ans)
		x = a[p[st]-1:p[i]+1]
		ans.extend(sorted(x))
		if(i < m-1):
			ans.extend(a[p[i]+1:p[i+1]-1])
		else:
			ans.extend(a[p[i]+1:])
		i += 1
	#print(ans)
	if(ans == sorted(ans)): print("YES")
	else: print("NO")