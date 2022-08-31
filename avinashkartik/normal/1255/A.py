from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
d = [0,1,1,2,2]
t = int(input())
for i in range(t):
	a,b = map(int,input().split())
	ans  = abs(a-b)//5 + d[abs(a-b)%5]
	print(ans)