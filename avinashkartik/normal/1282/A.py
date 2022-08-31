from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
t = int(input())
for y in range(t):
	a,b,c,r = map(int,input().split())
	if(a > b):
		a,b = b,a
	ct = b-a
	if(c > b):
		ct -= max(0,b-c+r)
	elif(c < a):
		ct -= max(0,c+r-a)
	else:
		#print(ct)
		if(c-r < a):
			ct -= c-a
		else:
			ct -= r
		#print(ct)
		if(c+r > b):
			ct -= b-c
		else:
			ct -= r
	print(max(ct,0))