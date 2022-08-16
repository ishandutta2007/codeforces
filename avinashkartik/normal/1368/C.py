from collections import *
from math import *

n = int(input())
ct = 0
i = 1
ans = [[0,0]]
while(ct <= n):
	ans.append([i,i])
	ans.append([i-1,i])
	ans.append([i,i-1])
	i += 1
	ct += 1
print(len(ans))
for i in ans:
	print(*i)