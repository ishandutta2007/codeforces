from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
l = [2**i-1 for i in range(40)]
x,d = map(int,input().split())
a = []
ct = 1
while(x != 0):
	for i in range(39):
		if l[i+1] > x:
			ind = i
			break
	x -= l[ind]
	for i in range(ind):
		a.append(ct)
	ct += d
print(len(a))
for i in a:
	print(i,end = " ")