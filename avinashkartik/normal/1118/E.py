from collections import *
from math import *

k,n = map(int,input().split())
K = k
ans = []
for i in range(1,n+1):
	for j in range(i+1,n+1):
		if(k <= 0):
			break
		ans.append([i,j])
		ans.append([j,i])
		k -= 2
if(len(ans) >= K):
	print("YES")
	for i in range(K):
		print(*ans[i])
else:
	print("NO")