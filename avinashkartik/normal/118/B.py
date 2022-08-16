from collections import *
from math import *

n = int(input())
ans = []
for i in range(n+1):
	s = []
	for j in range(i):
		s.append(str(j))
	for j in range(i,-1,-1):
		s.append(str(j))
	ans.append(s)
for i in range(n-1,-1,-1):
	ans.append(ans[i])
l = len(ans[n])
for i in ans:
	print((l-len(i))*" "+" ".join(i))