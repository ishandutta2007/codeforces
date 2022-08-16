from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
s = list(input())
n = int(input())
ct = 0
for i in s:
	if(i == 'T'):
		if(n == 0):
			print(ct+1)
			break
		else:
			n -= 1
	ct += 1
else:
	if(n %2 == 0):
		print(len(s))
	else:
		print(len(s)-1)