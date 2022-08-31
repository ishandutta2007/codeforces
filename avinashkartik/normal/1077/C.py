from collections import *
from math import *

n = int(input())
a = list(map(int,input().split()))
s = sum(a)
for i in range(n):
	a[i] = [a[i],i+1]
a.sort()
ans = []
for i in range(n-1):
	x = s-a[i][0]
	if(a[-1][0] == x/2):
		ans.append(a[i][1])
x = s-a[-1][0]
if(a[-2][0] == x/2):
	ans.append(a[-1][1])
print(len(ans))
print(*ans)