from math import *
from collections import *
n = int(input())
l = []
mu = mv = 0
for y in range(n):
    u,v = map(int,input().split())
    mu = max(mu,u)
    mv = max(mv,v)
    l.append([u,v])
l.sort()
flag = 0
for i in range(n-1):
    if(flag == 0):
        if(l[i+1][1] < l[i][1]):
            flag = 1
    else:
        if(l[i-1][0] <= l[i][1]):
            flag = 0
if(flag == 1):
    if(l[-2][0] <= l[-1][1]):
            print(mv)
    else:
        print(mu)
else:
    print(mv)