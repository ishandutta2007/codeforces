from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
  
n,m = map(int,input().split())
m = min(n,m)
ans = 1
for i in range(1,m+1):
	ans *= i
print(ans)