from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
t = int(input())
for y in range(t):
	d,n = map(int,input().split())
	x = int(sqrt(n))
	ans = x-1 + ceil(n/x)
	#print(ans)
	if(ans > d): print("NO")
	else: print("YES")