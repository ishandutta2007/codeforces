from math import *
from collections import *
t = int(input())
for y in range(t):
	a,b,x,y = map(int,input().split())
	l = max(x,a-x-1)
	w = max(y,b-y-1)
	print(max(l*b,a*w))