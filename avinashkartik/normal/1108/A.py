from collections import *
from math import *

n = int(input())
for y in range(n):
	a = list(map(int,input().split()))
	x = a[0]
	y = a[-1]
	if(x == y):
		if(a[-2] == a[-1]):
			x += 1
		else:
			y -= 1
	print(x,y)