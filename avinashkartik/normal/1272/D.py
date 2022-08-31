from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
mod = 10**9 + 7

n = int(input())
pre = [1 for i in range(n)]
preb = [1 for i in range(n)]
a = list(map(int,input().split()))
for i in range(1,n):
    if(a[i] > a[i-1]):
        pre[i] = pre[i-1]+1
for i in range(n-2,-1,-1):
    if(a[i] < a[i+1]):
        preb[i] = preb[i+1]+1
ans = max(pre)
for i in range(1,n-1):
    if(a[i-1] < a[i+1]):
        ans = max(ans,pre[i-1]+preb[i+1])
print(ans)