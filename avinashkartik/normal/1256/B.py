from math import *
from collections import *
t = int(input())
for y in range(t):
    n = int(input())
    a = list(map(int,input().split()))
    ct = n-1
    i = 1
    prev = -1
    while(ct != 0 and i <= n):
        #print(ct)
        x = a.index(i)
        #print(x)
        for j in range(x,max(i-1,prev),-1):
            if(a[j] < a[j-1]):
                a[j-1] , a[j] = a[j] , a[j-1]
                ct -= 1
            if(ct == 0):
                break
        i += 1
        prev = max(prev,x)
        #print(a)
    for i in a:
        print(i,end = " ")
    print()