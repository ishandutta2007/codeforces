from math import *
from collections import *

n = int(input())
a = list(map(int,input().split()))
ans = []
for i in range(n):
    m = 0
    for j in range(n-i):
        if(a[j] > a[m]):
            m = j
    if(a[m] != a[n-i-1]):
        ans.append([m,n-i-1])
        a[m],a[n-i-1] = a[n-i-1],a[m]
print(len(ans))
for i in ans:
    print(i[0],i[1])