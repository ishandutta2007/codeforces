from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
t = int(input())
for y in range(t):
	n = int(input())
	a = 0
	b = 0
	c = []
	d = []
	cc = 0
	ccc = 0
	dd = dict()
	l = []
	for i in range(n):
		s = input()
		l.append(s)
		dd[s] = 1
	for i in range(n):
		if(l[i][0] == '0' and l[i][-1] == '1'):
			b += 1
			t = l[i][::-1]
			if(t not in dd):
				c.append(i+1)
		if(l[i][0] == '1' and l[i][-1] == '0'):
			a += 1
			t = l[i][::-1]
			if(t not in dd):
				d.append(i+1)
		if(l[i][0] == '1' and l[i][-1] == '1'): cc += 1
		if(l[i][0] == '0' and l[i][-1] == '0'): ccc += 1
	if cc >0 : b += 1
	if ccc > 0 : a += 1
	if cc == n or ccc == n:
		print(0)
		continue
	if cc + ccc == n:
		print(-1)
		continue
	if(len(d) > len(c)):
		ind = (len(d)-len(c))//2
		if(len(d) < ind):
			print(-1)
			continue
		else:
			print(ind)
			for i in range(ind):
				print(d[i],end = " ")
			print()
	else:
		ind = (len(c)-len(d))//2
		if(len(c) < ind):
			print(-1)
			continue
		else:
			print(ind)
			for i in range(ind):
				print(c[i],end = " ")
			print()
	#print(ind,c,d)