from collections import *
from math import *

n,m,k = map(int,input().split())
a = []
if(k == 0):
	for i in range(m):
		for j in range(i+1,m):
			a.append([i+1,j+1])
else:
	for i in range(m-1,-1,-1):
		for j in range(i-1,-1,-1):
			a.append([i+1,j+1])
print(len(a))
for i in a:
	print(*i)