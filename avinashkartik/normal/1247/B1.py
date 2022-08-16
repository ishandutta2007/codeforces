from collections import *
from math import *
t = int(input())
for y in range(t):
    n,k,d = map(int,input().split())
    a = list(map(int,input().split()))
    pre = [0 for i in range(n)]
    m = 100000
    for i in range(n-d+1):
        #print(i,i+d)
        x = len(set(a[i:i+d]))
        m = min(x,m)
    print(m)