from collections import *
from math import *

n,k = list(map(int,input().split()))
a = list(map(int,input().split()))
c = Counter(a)
if(max(c.values()) > k):
	print("NO")
else:
	print("YES")
	for key,val in c.items():
		c[key] = 1
	ans = [0 for i in range(n)]
	for i in range(n):
		ans[i] = c[a[i]]
		c[a[i]] += 1
	mx = max(ans)
	c = Counter(ans)
	for i in range(n):
		if(mx == k):
			break
		if(c[ans[i]] > 1):
			c[ans[i]] -= 1
			ans[i] = mx+1
			mx += 1
	print(*ans)