from collections import *
n = int(input())
a = list(map(int,input().split()))
pre = [0 for i in range(n)]
pre[0] = a[0]
for i in range(1,n):
	pre[i] = pre[i-1]+a[i]
c = Counter(pre)
m = max(c.values())
print(n-m)