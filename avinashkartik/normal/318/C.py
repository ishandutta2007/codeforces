from collections import *
from math import *
from sys import *
n,m,k = map(int,input().split())
if(max(m,n) >= k):
    print(0)
elif(n+m > min(n,m)):
    ct = 0
    #print(m,n)
    if(n < 0):
        ct = ceil(-n/m)
        n = n + ct*m
    elif(m < 0):
        ct = ceil(-m/n)
        m = m + ct*n
    #print(m,n)
    while(max(n,m) < k):
        if(n < m):
            n = n+m
        else:
            m = n+m
        ct += 1
    print(ct)
else:
    print(-1)