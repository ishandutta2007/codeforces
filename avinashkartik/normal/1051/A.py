from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
t = int(input())
for y in range(t):
	s = list(input())
	a = [] 
	b = []
	c = []
	n = len(s)
	for i in range(n):
		if('0' <= s[i] <= '9'):
			a.append(i)
		elif(s[i].islower() == True):
			b.append(i)
		else:
			c.append(i)
	if(len(a) == 0):
		if(len(b) > 1):
			s[b[0]] = '1'
		else:
			s[c[0]] = '1'
	if(len(b) == 0):
		if(len(a) > 1):
			s[a[0]] = 'a'
		else:
			s[c[1]] = 'a'
	if(len(c) == 0):
		if(len(b) > 1):
			s[b[1]] = 'A'
		else:
			s[a[1]] = 'A'
	print("".join(s))