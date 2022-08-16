from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
n,m = map(int,input().split())
a = []
b = []
for i in range(n):
	a.append(list(map(int,input().split())))
for i in range(n):
	b.append(list(map(int,input().split())))
for i in range(n):
	for j in range(m):
		if(a[i][j] < b[i][j]):
			a[i][j],b[i][j] = b[i][j],a[i][j]

for i in range(n):
	for j in range(m-1):
		if(a[i][j] >= a[i][j+1]):
			print("Impossible")
			exit(0)
for i in range(n):
	for j in range(m-1):
		if(b[i][j] >= b[i][j+1]):
			print("Impossible")
			exit(0)
for i in range(m):
	for j in range(n-1):
		if(a[j][i] >= a[j+1][i]):
			print("Impossible")
			exit(0)
for i in range(m):
	for j in range(n-1):
		if(b[j][i] >= b[j+1][i]):
			print("Impossible")
			exit(0)
print("Possible")