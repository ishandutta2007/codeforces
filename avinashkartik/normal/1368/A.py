from collections import *
from math import *

t = int(input())
for y in range(t):
	a,b,n = list(map(int,input().split()))
	o = 0
	if(a > b):
		a,b = b,a
	while(b <= n):
		a += b
		a,b = b,a
		o += 1
	print(o)