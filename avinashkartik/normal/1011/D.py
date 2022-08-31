from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)

m,n = map(int,input().split())
print(1)
a = [0 for i in range(n)]
x = int(input())
if(x == 0):
	exit(0)
a[0] = -1*x
for i in range(1,n):
	sys.stdout.flush()
	print(1)
	x = int(input())
	a[i] = -1*x

i = 0
l = 1
h = m
while(h >= l):
	sys.stdout.flush()
	mid = (h+l)//2
	print(mid)
	x = int(input())
	if(x == 0 or x == -2):
		exit(0)
	if(a[i]*x == 1):
		h = mid - 1
	else:
		l = mid + 1
	i += 1
	i %= n