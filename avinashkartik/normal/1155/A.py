from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
n = int(input())
a = list(input())
b = sorted(a)
ind = -1
for i in range(n):
	if(b[i] != a[i]):
		ind = i
		break
if(ind == -1):
	print("NO")
else:
	for i in range(ind+1,n):
		if(a[i] == b[ind]):
			ind2 = i
			break
	print("YES")
	print(ind+1,ind2+1)