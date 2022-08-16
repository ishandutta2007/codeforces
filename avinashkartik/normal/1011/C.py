from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)

n = int(input())
y = int(input())
z = y
a = list(map(int,input().split()))
b = list(map(int,input().split()))
if(1 in a or 1 in b):
	print(-1)
	exit(0)
for i in range(n):
	x = y/(a[i]-1)
	y += x
for i in range(n):
	x = y/(b[i]-1)
	y += x
print(y-z)