from math import *
from collections import *
t = int(input())
for y in range(t):
    n = int(input())
    a = list(map(int,input().split()))
    c = Counter(a)
    s = max(a)
    pre = [0 for i in range(s+2)]
    for i in range(s,0,-1):
        if(i not in c):
            pre[i] = pre[i+1]
        else:
            pre[i] = c[i] + pre[i+1]
    for i in range(s,0,-1):
        if(pre[i] >= i):
            print(i)
            break