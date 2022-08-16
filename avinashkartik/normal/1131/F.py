from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)

def find(x):
    if (p[x] == x):
        return x
    p[x] = find(p[x])
    return p[x]

def merge(x,y):
    a = find(x)
    b = find(y)
    #print(a,b)
    if(a != b):
        if(sz[a] > sz[b]): a,b = b,a
        p[a] = b
        sz[b] += sz[a]
        arr[b].extend(arr[a])

n = int(input())
p = [i for i in range(n+1)]
sz = [1 for i in range(n+1)]
arr = [[i] for i in range(n+1)]
for i in range(n-1):
    u,v = map(int,input().split())
    merge(u,v)
    #print(p)
for i in arr:
    if len(i) == n:
        for j in i:
            print(j,end = " ")
        print()
        break