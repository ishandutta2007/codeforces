from math import *
t = int(input())
a = []
k = 1
for i in range(9):
    s = len(a)
    a.append(k)
    for j in range(s):
        a.append(a[j]+k)
    k *= 3
a.append(k)
for y in range(t):
    n = int(input())
    for i in a:
        if i >= n:
            print(i)
            break