from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)

n = int(input())
ans = 0
for i in range(n):
	x,y = map(int,input().split())
	ans = max(ans,x+y)
print(ans)