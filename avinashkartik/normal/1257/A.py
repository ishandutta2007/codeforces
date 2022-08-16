from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
t = int(input())
for y in range(t):
	n,x,a,b = map(int,input().split())
	if(a > b):
		a,b = b,a
	while(x != 0):
		if(b < n):
			b += 1
			x -= 1
		elif(a > 1):
			a -= 1
			x -= 1
		else:
			break
	print(abs(b-a))