from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
t = int(input())
for y in range(t):
	a,b,n = map(int,input().split())
	l = [a,b,a^b]
	print(l[n%3])