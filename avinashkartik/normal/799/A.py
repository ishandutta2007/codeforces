from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
mod = 10**9 + 7

n,t,k,d = map(int,input().split())
if(k >= n):
    print("NO")
else:
    s = (d//t)*k
    if(s < n-k):
        print("YES")
    else:
        print("NO")