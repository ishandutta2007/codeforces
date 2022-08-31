from collections import *
n = int(input())
a = list(map(int,input().split()))
c = Counter(a)
for i in range(2*n):
	a[i] = [a[i],i]
a.sort()
ans = [0 for i in range(2*n)]
da, db = {}, {}
f = 0
for i in range(2*n):
	if(c[a[i][0]] == 1): continue
	ans[a[i][1]] = f + 1
	if(f&1):
		da[a[i][0]] = 1
	else:
		db[a[i][0]] = 1
	f ^= 1
for i in range(2*n):
	if(ans[a[i][1]] != 0): continue
	ans[a[i][1]] = f+1
	if(f&1):
		da[a[i][0]] = 1
	else:
		db[a[i][0]] = 1
	f ^= 1
print(len(da)*len(db))
print(*ans)