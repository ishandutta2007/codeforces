from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)

x,y,z = map(int,input().split())
if(z == 0):
	if(x == y):
		print('0')
	elif(x > y):
		print('+')
	else:
		print('-')
else:
	if(x > y+z):
		print('+')
	elif(y > x+z):
		print('-')
	else:
		print('?')