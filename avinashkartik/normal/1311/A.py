from math import *
from collections import *
t = int(input())
for y in range(t):
	n,m = map(int,input().split())
	if(n == m):
		print(0)
	elif(n > m):
		if (n-m)&1:
			print(2)
		else:
			print(1)
	else:
		if (m-n)&1:
			print(1)
		else:
			print(2)