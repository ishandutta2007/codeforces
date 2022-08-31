from math import *
from collections import *
t = int(input())
for y in range(t):
    n,m = map(int,input().split())
    a = input()
    c1 = []
    c0 = []
    for i in range(n):
        if(a[i] == '1'):
            c1.append(i)
        else:
            c0.append(i)
    st = 0
    lst = 0
    len0 = len(c0)
    while(st < len0 and m != 0):
        x = c0[st] - st
        #print(x,m)
        if(x > m):
            lst = x-m
            m = 0
        else:
            st += 1
            m -= x
    l = ['a' for i in range(n)]
    for i in range(st):
        l[i] = '0'
    if st == len0:
        for i in range(st,n):
            l[i] = '1'
    else:
        for i in range(st,c0[st]):
            l[i] = '1'
        if(lst != 0):
            l[lst+st] = '0'
            l[c0[st]] = '1'
        else:
            l[c0[st]] = '0'
        for i in c1:
            if(i > c0[st]):
                l[i] = '1'
        for i in c0:
            if(i > c0[st]):
                l[i] = '0'
    print("".join(l))