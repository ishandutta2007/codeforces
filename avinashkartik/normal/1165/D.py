from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
t = int(input())
for y in range(t):
	n = int(input())
	a = list(map(int,input().split()))
	a.sort()
	x = a[0]*a[-1]
	fact = []
	for i in range(2,int(sqrt(x))+1): 
		if(x % i == 0):
			fact.append(i)
			if(i != sqrt(x)):
				fact.append(x//i)
	fact.sort()
	if(fact == a):
		print(x)
	else:
		print(-1)