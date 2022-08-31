from collections import *
from math import *
t = int(input())
for y in range(t):
    n,k,d = map(int,input().split())
    a = list(map(int,input().split()))
    pre = [0 for i in range(n)]
    D = dict()
    for i in range(d):
        if a[i] not in D:
            D[a[i]] = 1
        else:
            D[a[i]] += 1
    m = len(D)
    m1 = m
    for i in range(d,n):
        #print(i,i-d)
        #print(m,m1)
        if a[i] not in D or D[a[i]] == 0:
            D[a[i]] = 1
            m += 1
        else:
            D[a[i]] += 1

        if D[a[i-d]] == 1:
            D[a[i-d]] = 0
            m -= 1
        else:
            D[a[i-d]] -= 1
        m1 = min(m1,m)
    print(m1)