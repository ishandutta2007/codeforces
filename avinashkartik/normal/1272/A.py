from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
mod = 10**9 + 7

tt = int(input())
for y in range(tt):
    a,b,c = map(int,input().split())
    m1 = max(a,b,c)
    m2 = min(a,b,c)
    if(m1 == m2):
        print(0)
    else:
        if(a == m1):
            a -= 1
        if(b == m1):
            b -= 1
        if(c == m1):
            c -= 1
        m1 -= 1
        if(m1 == m2):
            print(0)
        else:
            if(a == m2):
                a += 1
            if(b == m2):
                b += 1
            if(c == m2):
                c += 1
            print(abs(a-b) + abs(b-c) + abs(a-c))