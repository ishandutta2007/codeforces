from collections import *
from math import *
n,k = map(int,input().split())
a = list(map(int,input().split()))
a = Counter(a)
ct = [0 for i in range(101)]
#print(a)
for i in a.keys():
    #print(a[i])
    for j in range(a[i],0,-1):
        ct[j] += a[i]//j
ans = 0
for i in range(100,-1,-1):
    if(ct[i] >= n):
        ans = i
        break
print(ans)