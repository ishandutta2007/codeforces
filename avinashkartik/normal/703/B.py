from collections import *
n,k = map(int,input().split())
a = list(map(int,input().split()))
cap = [0 for i in range(n)]
c = list(map(int,input().split()))
for i in c:
	cap[i-1] = 1
s = sum(a)
ans = 0
for i in range(n):
	if(cap[i] == 1):
		ans += a[i]*(s-a[i])
		s -= a[i]
	elif(cap[i-1] != 1): ans += a[i]*a[i-1]
print(ans)