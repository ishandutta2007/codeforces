from collections import *
from math import *
n,k = map(int,input().split())
a = list(map(int,input().split()))
d = Counter(a)
a.sort()
val = [0 for i in range(400005)]
a = list(set(a))
a.sort()
n1 = len(a)
val[0] = d[a[0]]
for i in range(1,n1):
    val[i] = val[i-1] + d[a[i]]
m = n1
#print(n1)
for m in range(n1,0,-1):
    s = ceil(log2(m))
    if s*n <= 8*k:
        break
#print(m,val[:10])
m1 = val[m-1]
for i in range(m,n1):
    m1 = max(m1,val[i]-val[i-m])
print(n-m1)