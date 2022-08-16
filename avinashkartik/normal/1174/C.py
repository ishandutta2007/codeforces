from math import *
n = int(input())
a = [0 for i in range(n+1)]
ct = 1
for i in range(2,n+1):
    if(a[i] == 0):
        a[i] = ct
        for j in range(i*i,n+1,i):
            a[j] = ct
        ct += 1
for i in range(2,n+1):
    print(a[i],end = " ")
print()