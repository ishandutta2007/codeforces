from math import *
from collections import *
n,m = map(int,input().split())
maxx = (n-m)*(n-m+1)//2
x = n//m
y = n%m
min1 = x*(x-1)//2
min2 = x*(x+1)//2
minn = y*min2 + (m-y)*min1
print(minn,maxx)