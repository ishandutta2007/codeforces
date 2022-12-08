from __future__ import print_function
from collections import Counter
from queue import Queue
import sys
import math
import os.path
sys.setrecursionlimit(10**9)
def log(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)
def ni():
    return map(int, input().split())
def nio(offset):
    return map(lambda x: int(x) + offset, input().split())
def nia():
    return list(map(int, input().split()))
def toString(aList, sep=" "):
    return sep.join(str(x) for x in aList)
def mapInvertIndex(aList):
    return {k: v for v, k in enumerate(aList)}
def sortId(arr):
    return sorted(range(arr), key=lambda k: arr[k])
n, k = ni()
c = nia()
f = nia()
h = nia()
h.insert(0,0)
cc = Counter(c)
cf = Counter(f)
n1 = n+1
k1 = k+1
nk1 = n*k+1
dp = [[0]*nk1 for _ in range(n1)]
for ni in range(1,n1):
    for ki in range(1,nk1):
        mficount = min(k,ki) + 1        
        for kii in range(mficount):
            # log(ni,ki, kii, dp[ni][ki], dp[ni-1][ki-kii] + h[kii])
            dp[ni][ki] = max(dp[ni][ki], dp[ni-1][ki-kii] + h[kii])
res = 0
for fk,fv in cf.items():
    res += dp[fv][cc[fk]]
print(res)