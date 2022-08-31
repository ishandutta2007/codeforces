from math import *
from collections import *
t = int(input())
for y in range(t):
    n,k = map(int,input().split())
    a = list(map(int,input().split()))
    a.sort()
    m = max(a[0],n+1-a[k-1])
    for i in range(k-1):
        m = max(m,ceil((a[i+1]-a[i]+1)/2))
    print(m)