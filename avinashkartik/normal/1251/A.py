from collections import *
from math import *
n = int(input())
for y in range(n):
    t = list(input())
    s = len(t)
    ct = 1
    ans = []
    for i in range(1,s):
        if t[i] != t[i-1]:
            if ct%2 == 1:
                ans.append(t[i-1])
            ct = 1
        else:
            ct += 1
    if ct%2 == 1:
        ans.append(t[-1])
    ans = list(set(ans))
    ans.sort()
    print("".join(ans))