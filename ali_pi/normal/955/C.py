import sys
xrange = range
input = raw_input
import math
from math import sqrt
import bisect

small = 10**5+1
big = 10**18+1

pos = []
f = pos.append
j = 2
while True:
    j2 = j*j
    i = j*j2
    if i>=big:
        break
    while i<big:
        f(i)
        i *= j2
    j += 1
pos2 = [p for p in pos if not sqrt(p).is_integer()]
pos2.sort()
prev = -1
pos = []
f = pos.append
for p in pos2:
    if p==prev:
        continue
    f(p)
    prev = p
q = int(input())
out = []
for line in sys.stdin:
    L,R = line.split()
    L = int(L)
    R = int(R)
    a = -1
    b = len(pos)
    while b-a>1:
        m = (a+b)//2
        if pos[m]<L:
            a=m
        else:
            b=m
    under = a
    a = -1
    b = len(pos)
    while b-a>1:
        m = (a+b)//2
        if pos[m]<=R:
            a = m
        else:
            b = m
    upper = a
    Lupp = max(int(sqrt(L)-1),0)
    while Lupp*Lupp<L:
        Lupp+=1
    Rdown = int(sqrt(R))+1
    while Rdown*Rdown>R:
        Rdown-=1
    count = max(0,Rdown-Lupp+1)
    out.append(str(upper-under+count))
print('\n'.join(out))