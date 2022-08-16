from collections import *
from math import *
n = int(input())
a = list(input())
k = 0
ans = 0
for i in range(n):
    if a[i] == '-':
        ans -= 1
    else:
        ans += 1
    k = min(k,ans)
print(ans-k)