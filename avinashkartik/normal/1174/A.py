from math import *
n = int(input())
l = list(map(int,input().split()))
ans = 0
l.sort()
d = dict()
for i in l:
    if i not in d:
        d[i] = 1
    else:
        d[i] += 1
for key,val in d.items():
    if val == 2*n:
        ans = -1

if(ans != -1):
    for i in l:
        print(i,end = " ")
    print()
else:
    print(ans)