from math import *
from collections import *
t = int(input())
for y in range(t):
    n = int(input())
    a,b,c = map(int,input().split())
    s = input()
    ct = 0
    l = ['0' for i in range(n)]
    for i in range(n):
        if(s[i] == 'R' and b != 0):
            ct += 1
            l[i] = 'P'
            b -= 1
        elif(s[i] == 'P' and c != 0):
            ct += 1
            l[i] = 'S'
            c -= 1
        elif(s[i] == 'S' and a != 0):
            ct += 1
            l[i] = 'R'
            a -= 1
    for i in range(n):
        if(l[i] == '0' and a != 0):
            l[i] = 'R'
            a -= 1
        elif(l[i] == '0' and b != 0):
            l[i] = 'P'
            b -= 1
        elif(l[i] == '0'):
            l[i] = 'S'
            c -= 1
    if(ct >= n/2):
        print("YES")
        print("".join(l))
    else:
        print("NO")