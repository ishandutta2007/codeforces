from collections import *
n = int(input())
a = list(map(int,input().split()))
a += a
ct = 0
ans = 0
for i in range(2*n):
	if(a[i] == 1):
		ct += 1
	else:
		ans = max(ans,ct)
		ct = 0
print(ans)