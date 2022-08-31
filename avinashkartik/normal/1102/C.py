from collections import *
from math import *

n,x,y = list(map(int,input().split()))
a = list(map(int,input().split()))
if(x > y):
	print(n)
else:
	ct = 0
	for i in range(n):
		if(a[i] <= x): ct += 1
	print(ceil(ct/2))