from collections import *
from math import *
n = int(input())
a = list(map(int,input().split()))
k = 1e+18
for i in range(n):
    k = min(k,a[i]//max(i,n-i-1))
print(k)