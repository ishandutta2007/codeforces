from math import *
te = int(input())
for y in range(te):
	n,x = map(int,input().split())
	a = list(map(int,input().split()))
	if(x in a):
		print(1)
		continue
	m = max(a)
	if(x < m):
		print(2)
		continue
	else:
		print(ceil(x/m))