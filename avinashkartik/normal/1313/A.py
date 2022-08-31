from math import *
from collections import *
t = int(input())
for y in range(t):
	l = list(map(int,input().split()))
	l.sort()
	a = l[2]
	b = l[1]
	c = l[0]
	ct = 0
	if(a > 0):
		ct += 1
		a -= 1
	if(b > 0):
		ct += 1
		b -= 1
	if(c > 0):
		ct += 1
		c -= 1
	if(a > 0 and b > 0):
		ct += 1
		a -= 1
		b -= 1
	if(a > 0 and c > 0):
		ct += 1
		a -= 1
		c -= 1
	if(c > 0 and b > 0):
		ct += 1
		c -= 1
		b -= 1
	if(a > 0 and b > 0 and c > 0):
		ct += 1
	print(ct)