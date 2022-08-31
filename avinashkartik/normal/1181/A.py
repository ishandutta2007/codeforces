from collections import *
from math import *
from sys import *
n,m,k = map(int,input().split())
x = (n+m)//k
flag = 1
if(n//k+m//k == x):
    flag = 0
if(n%k == 0 or flag == 0):
    u = 0
else:
    u = k-n%k
if(m%k == 0 or flag == 0):
    v = 0
else:
    v = k-m%k
y = min(u,v)
print(x,y)