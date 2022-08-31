from math import *
from collections import *
n,m,d = map(int,input().split())
a = list(map(int,input().split()))
suf = [0 for i in range(m)]
suf[-1] = a[-1]
for i in range(m-2,-1,-1):
    suf[i] = suf[i+1] + a[i]
#print(suf)
l = [0 for i in range(n)]
prev = -1
for i in range(m):
    if(n-(prev+d) >= suf[i]):
        st = prev+d
    else:
        st = prev+1
    #print(st,st+a[i])
    for j in range(st,st+a[i]):
        l[j] = i+1
    prev = st+a[i]-1
if(prev + d < n):
    print("NO")
else:
    print("YES")
    for i in l:
        print(i,end = " ")
    print()