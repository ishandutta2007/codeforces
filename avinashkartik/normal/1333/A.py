from collections import *
from math import *
t = int(input())
for y in range(t):
	n,m = map(int,input().split())
	a = [['B' for i in range(m)] for j in range(n)]
	for i in range(n):
		for j in range(m):
			if (i+j)%2 == 1:
				a[i][j] = 'W'
	if (m*n)%2 == 0:
		for i in range(n):
			f = 0
			for j in range(m):
				if(a[i][j] == 'W'):
					a[i][j] = 'B'
					f = 1
					break
			if(f == 1):
				break
	for i in range(n):
		print("".join(a[i]))