from collections import *
n,k = list(map(int,input().split()))
a = list(map(int,input().split()))
ans = [0 for i in range(n+1)]
m = n+1
for i in range(k):
	if(a[i] >= m):
		continue
	for j in range(a[i],m):
		ans[j] = a[i]
	m = a[i]
for i in ans[1:]:
	print(i,end = " ")
print()