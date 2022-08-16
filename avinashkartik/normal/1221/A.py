from math import *
t = int(input())
for y in range(t):
    n = int(input())
    l = list(map(int,input().split()))
    l.sort()
    a = [0 for i in range(12)] 
    for i in l:
        u = int(log2(i))
        if(u < 12):
            a[u] += 1
    for i in range(11):
        a[i+1] += a[i]//2
    if(a[11] != 0):
        print("YES")
    else:
        print("NO")