from math import *
from collections import *
n,m = map(int,input().split())
a = list(map(int,input().split()))
pre = [0,a[0]]
for i in range(1,n):
    pre.append(pre[-1]+a[i])
i = 0
j = 1
maxx = 0
while(i < n):
    #print(i,j)
    while(j <= n and pre[j] - pre[i] <= m):
        j += 1
    maxx = max(maxx,j-i-1)
    i += 1
print(maxx)