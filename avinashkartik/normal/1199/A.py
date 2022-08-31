from collections import *
n,x,y = map(int,input().split())
a = list(map(int,input().split()))
i = 0
for i in range(n):
    val = a[i]
    for j in range(max(0,i-x),min(n,i+y+1)):
        if val > a[j]:
            break
    else:
        break
print(i+1)