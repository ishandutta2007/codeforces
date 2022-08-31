from collections import *
from math import *
t = int(input())
for y in range(t):
    s = list(input())
    n = len(s)
    a = []
    b = []
    for i in s:
        if int(i)%2 == 0:
            a.append(i)
        else:
            b.append(i)
    j = 0
    k = 0
    n1 = len(a)
    n2 = len(b)
    for i in range(n):
        if j == n1:
            s[i] = b[k]
            k += 1
        elif k == n2:
            s[i] = a[j]
            j += 1
        elif a[j] < b[k]:
            s[i] = a[j]
            j += 1
        else:
            s[i] = b[k]
            k += 1
    print("".join(s))