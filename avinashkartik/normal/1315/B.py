from math import *
from collections import *
t = int(input())
for y in range(t):
	a,b,p = map(int,input().split())
	s = input()
	n = len(s)
	i = n-2
	ans = n
	ct = 0
	while(i >= 0):
		st = s[i]
		while(i >= 0 and s[i] == st):
			i -= 1
		if(st == 'A'):
			ct += a
		else:
			ct += b
		if(ct <= p):
			ans = i+2
	print(ans)