from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
t = int(input())
for y in range(t):
	l = list(map(int,input().split()))
	ans = sum(l)//2
	print(ans)