from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)

x,y = map(int,input().split())
x1 = min(x,y)
y1 = max(x,y)
if(x1 == 1):
	s = y1%6
	if(s == 4):
		s = 2
	if(s == 5):
		s = 1
	print(y1-s)
	exit(0)
if(x1 == 2):
	if(y1 == 2):
		print(0)
	elif(y1 == 3):
		print(4)
	elif(y1 == 7):
		print(12)
	else:
		print(2*y1)
else:
	print(x1*y1 - (x1*y1)%2)