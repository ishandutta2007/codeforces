from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
t = int(input())
for y in range(t):
	h,m = map(int,input().split())
	print((23-h)*60+60-m)