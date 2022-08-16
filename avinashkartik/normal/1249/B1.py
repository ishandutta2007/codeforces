from math import *
t = int(input())
for y in range(t):
    n = int(input())
    a = list(map(int,input().split()))
    for i in range(n):
        j = i
        ct = 0
        while(i != a[j]-1):
            j = a[j]-1
            ct += 1
        print(ct+1,end = " ")
    print()