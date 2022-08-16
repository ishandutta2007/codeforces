from collections import *
from math import *

a,b = list(map(int,input().split()))
ub = min(a,b-1)
lb = b//2 + 1
print(max(0,ub-lb+1))