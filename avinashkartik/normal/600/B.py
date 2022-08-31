from collections import *
from math import *
n , m = map(int,input().split())
a = list(map(int,input().split()))
l = list(map(int,input().split()))
b = []
for i in range(m):
    b.append([l[i],i])
a.sort()
b.sort()
i = 0
for j in range(m):
    while(i < n and a[i] <= b[j][0]):
        i += 1
    l[b[j][1]] = i
for i in l:
    print(i,end = " ")
print()