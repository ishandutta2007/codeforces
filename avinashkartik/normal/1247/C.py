from collections import *
from math import *
n,p = map(int,input().split())
for i in range(30):
    if(n - i*p <= 0):
        print(-1)
        break
    x = n-i*p
    ct = bin(x).count('1')
    if ct <= i and x >= i:
        print(i)
        break
else:
    print(-1)