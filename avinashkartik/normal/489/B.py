from math import *
from collections import *

n = int(input())
a = list(map(int,input().split()))
m = int(input())
b = list(map(int,input().split()))
i = 0
j = 0
prev = 0
ct = 0
a.sort()
b.sort()
while(i < n):
    j = prev
    while(j < m):
        if(abs(a[i] - b[j]) <= 1):
            ct += 1
            prev = j+1
            break
        j += 1
    i += 1
print(ct)