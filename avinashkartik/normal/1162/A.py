from math import *
from collections import *
n,h,m = map(int,input().split())
a = [h for i in range(n)]
for i in range(m):
    u,v,x = map(int,input().split())
    for j in range(u-1,v):
        a[j] = min(a[j],x)
ans = 0
for i in a:
    ans += i*i
print(ans)