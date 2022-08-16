from math import *
n,k = map(int,input().split())
d = dict()
for i in range(n):
    a = int(input())
    if a not in d :
        d[a] = 1
    else:
        d[a] += 1
g = b = 0
for i in d:
    g += (d[i]//2)*2
    b += d[i]%2
print(g+ceil(b/2))