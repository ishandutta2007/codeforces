from collections import *
from math import *

n = int(input())
a = list(map(int,input().split()))
ct4,ct2,ct1 = [],[],[]
d = dict()
for i in a:
	if i not in d:
		d[i] = 0
	d[i] += 1
	if(d[i] == 4):
		d[i] = 0
		ct4.append(i)
for k,v in d.items():
	if v == 0: continue
	if v >= 2:
		ct2.append(k)
		v -= 2
	if v == 1:
		ct1.append(k)
if(n&1 and len(ct1) != 1):
	print("NO")
	exit(0)
ans = [[0 for j in range(n)] for i in range(n)]
for i in range((n+1)//2):
	for j in range((n+1)//2):
		if(j == (n-j-1) and i == (n-i-1)):
			ct = 1
		elif(i == (n-i-1) or j == (n-j-1)):
			ct = 2
		else:
			ct = 4
		if(ct == 4):
			if(len(ct4) == 0):
				print("NO")
				exit(0)
			y = ct4[-1]
			ct4.pop()
		elif(ct == 2):
			if(len(ct2) == 0):
				if(len(ct4) == 0):
					print("NO")
					exit(0)
				y = ct4[-1]
				ct4.pop()
				ct2.append(y)
			else:
				y = ct2[-1]
				ct2.pop()
		else:
			y = ct1[-1]
			ct1.pop()
		ans[i][j], ans[i][n-j-1], ans[n-i-1][j], ans[n-i-1][n-j-1] = y, y, y, y
print("YES")
for i in ans:
	print(*i)