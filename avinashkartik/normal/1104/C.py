from math import *
from collections import *
s = input()
x = 1
y = 1
for i in s:
	if(i == '1'):
		print(y,3)
		y += 1
		if(y == 5):
			y = 1
	else:
		print(x,1)
		x += 2
		if(x == 5):
			x = 1