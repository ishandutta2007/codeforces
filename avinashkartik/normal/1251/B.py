from collections import *
from math import *
t = int(input())
for y in range(t):
    n = int(input())
    l = []
    for i in range(n):
        l.append(list(input()))
    ct = 0
    s = 0
    flag = 0
    for i in l:
        ct += i.count('1')
        s += len(i)
        if len(i) % 2 == 1:
            flag = 1
    if s%2 == 1:
        print(n)
    elif ct%2 == 0 or flag == 1:
        print(n)
    else:
        print(n-1)