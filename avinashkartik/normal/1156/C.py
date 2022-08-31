from collections import *
from math import *
n,z = map(int,input().split())
a = list(map(int,input().split()))
vis = [0 for i in range(n)]
a.sort()
#print(a)
i = 0
j = n//2
ct = 0
while(j < n):
    if(vis[i] == 1):
        i += 1
    elif(a[j] - a[i] >= z):
        ct += 1
        vis[i] = 1
        vis[j] = 1
        i += 1
        j += 1
    else:
        j += 1
print(ct)