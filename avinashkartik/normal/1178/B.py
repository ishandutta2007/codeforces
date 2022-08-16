from collections import *
from math import *
s = list(input())
n = len(s)
i = 0
a = []
while(i < n):
    ctv = 0
    while(i<n and s[i] != 'o'):
        i += 1
        ctv += 1
    cto = 0
    a.append(ctv)
    while(i<n-1 and not (s[i] == 'v' and s[i+1] =='v')):
        if s[i] == 'o':
            cto += 1
        i += 1
    a.append(cto)
    if(i == n-1):
        break
a.pop()
st = 0
if a[0] < 2:
    st = 2
n = len(a)
ans = 0
ct3 = 0
ct1 = 0
for i in range(n-1,st-1,-2):
    ct3 += a[i]-1
for i in range(st,n-2,2):
    ct1 += a[i]-1
    ct2 = a[i+1]
    ct3 -= a[i]-1
    #print(ct1,ct2,ct3)
    ans += ct1*ct2*ct3
print(ans)