from math import *
n,m,k = map(int,input().split())
l = list(map(int,input().split()))
a = [0 for i in range(n+1)]
ans = 0
for M in range(m):
    min1 = 0
    for i in range(1,n+1):
        a[i] = a[i-1] + l[i-1]
        if(i % m == M):
            a[i] -= k
            ans = max(ans,a[i]-min1)
        min1 = min(min1,a[i])
    #print(a)
print(ans)