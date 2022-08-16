from collections import *
from math import *
s = input()
a = [0 for i in range(26)]
for i in s:
    ind = ord(i) - ord('a')
    a[ind] += 1
n = len(s)
i = 0
j = 25
while(i < j):
    if(a[i]%2 == 1):
        if(a[j]%2 == 1):
            a[j] -= 1
            a[i] += 1
            j -= 1
            i += 1
        else:
            j -= 1
    else:
        i += 1
b = ['a' for i in range(n)]
f = 0
la = n-1
for i in range(26):
    ch = chr(i+ord('a'))
    while(a[i] != 0):
        if a[i] == 1:
            b[n//2] = ch
            a[i] -= 1
        elif a[i] != 0:
            b[f] = ch
            f += 1
            b[la] = ch
            la -= 1
            a[i] -= 2
print(''.join(b))