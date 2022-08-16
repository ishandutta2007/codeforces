from math import *
from collections import *
t = int(input())
for y in range(t):
    n = int(input())
    a = list(map(int,input().split()))
    d = [0,0,0]
    for i in range(n):
        ind = a[i]%3
        d[ind] += 1
    x = min(d[1],d[2])
    d[0] += x
    d[1] -= x
    d[2] -= x
    d[0] += d[2]//3 + d[1]//3
    print(d[0])