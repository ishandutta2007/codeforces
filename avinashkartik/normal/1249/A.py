from math import *
t = int(input())
for y in range(t):
    n = int(input())
    a = list(map(int,input().split()))
    flag = 0
    a.sort()
    for i in range(1,n):
        if a[i] - a[i-1] == 1:
            flag = 1
            break
    if(flag == 1):
        print(2)
    else:
        print(1)