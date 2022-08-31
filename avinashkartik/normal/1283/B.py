from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
t = int(input())
for y in range(t):
	n,k = map(int,input().split())
	print(min(n,n//k*k+k//2))