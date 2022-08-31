from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)

mod = 10**9 + 7
t = int(input())
for y in range(t):
	x = int(input())
	s = input()
	l = len(s)
	key = 0

	for i in range(x):
		if(s[i] == '1'): continue
		if(key == 0 and l < x):
			s += (int(s[i])-1)*s[i+1:]
		l = i+1 + (l-(i+1))*(int)(s[i])
		if(l >= mod):
			key = 1
		l %= mod
	print(l)