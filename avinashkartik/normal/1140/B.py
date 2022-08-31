from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
t = int(input())
for y in range(t):
	n = int(input())
	a = input()
	ct = ct1 = 0
	for i in range(n):
		if(a[i] == '>'):
			ct = i
			break
	for i in range(n-1,-1,-1):
		if(a[i] == '<'):
			ct1 = n-1-i
			break
	print(min(ct,ct1))