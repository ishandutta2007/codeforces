import math
import sys
from collections import defaultdict, Counter
from functools import lru_cache

t = int(input())
for _ in range(t):
    n = int(input())
    arr = [int(i) for i in input().split()]
    s = input()
    ans = [0 for i in range(n)]
    g = []
    l = []
    
    for i in range(n):
        if s[i] == '0':
            g.append(i)
        else:
            l.append(i)
    
    g.sort(key=lambda x: arr[x])
    l.sort(key=lambda x: arr[x])
    
    for i in range(len(g)):
        ans[g[i]] = i + 1
    
    for i in range(len(l)):
        ans[l[i]] = i + 1 + len(g)
    
    print(*ans)