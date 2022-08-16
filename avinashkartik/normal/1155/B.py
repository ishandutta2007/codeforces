from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
n = int(input())
a = list(input())
t = (n-11)//2
s = a[:2*t+1].count('8')
if(s >= t+1):
	print("YES")
else:
	print("NO")