from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)

mod = 10**9 + 7
a = int(input())
b = int(input())
c = int(input())
d = int(input())
d1 = d
e = int(input())
f = int(input())
ans = min(a,d)
c1 = e*ans
ans1 = min(b,c,d)
c2 = f*ans1
d -= ans
d1 -= ans1
ans = min(a,d1)
ans1 = min(b,c,d)
c1 += f*ans1
c2 += e*ans
print(max(c1,c2))