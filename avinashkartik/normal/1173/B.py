from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)

n = int(input())
s = n//2 + 1
print(s)
ct = 0
x = 1
y = 1
for i in range(n):
	print(x,y)
	if(x < s):
		x += 1
	else:
		y += 1