from collections import *
from math import *

n,m,k = map(int,input().split())
a = []
for i in range(n):
	a.append(input())
ans = 0
if k == 1:
	for i in range(n):
		ans += a[i].count('.')
else:
	for i in range(n): 
		ct = 0
		for j in range(m):
			if a[i][j] == '.':
				ct += 1
			if(j-k >= 0):
				if a[i][j-k] == '.':
					ct -= 1
			if(ct == k):
				ans += 1
	for i in range(m): 
		ct = 0
		for j in range(n):
			if a[j][i] == '.':
				ct += 1
			if(j-k >= 0):
				if a[j-k][i] == '.':
					ct -= 1
			if(ct == k):
				ans += 1
print(ans)