from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
mod = 10**9 + 7

tt = int(input())
for y in range(tt):
    a = input()
    if(len(a) == 0):
        print(0)
        print(a)
        continue
    l = a.count('L')
    r = a.count('R')
    u = a.count('U')
    d = a.count('D')
    ll = min(l,r)
    uu = min(u,d)
    if(uu == 0 and ll > 0):
        print(2)
        print("LR")
        continue
    if(ll == 0 and uu > 0):
        print(2)
        print("UD")
        continue
    print((ll+uu)*2)
    print(ll*'R',end = "")
    print(uu*'U',end = "")
    print(ll*'L',end = "")
    print(uu*'D')