from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
t = [chr(48+i) for i in range(10)]
s = [chr(97+i) for i in range(26)]
l = [chr(65+i) for i in range(26)]
l.extend(s)
l.extend(t)
t = int(input())
for y in range(t):
	n,m,k = map(int,input().split())
	a = []
	ans = [[0 for i in range(m)]for j in range(n)]
	r = 0
	for i in range(n):
		a.append(input())
		r += a[-1].count('R')
	val = r//k
	ind = 0
	ct = 0
	for i in range(n):
		if(i%2 == 0):
			for j in range(m):
				if(ind < r%k):
					if(ct == val+1 and ind < k-1):
						ind += 1
						ct = 0
				else:
					if(ct == val and ind < k-1):
						ind += 1
						ct = 0
				if(a[i][j] == 'R'):
					ct += 1
				ans[i][j] = l[ind]
		else:
			for j in range(m-1,-1,-1):
				if(ind < r%k):
					if(ct == val+1 and ind < k-1):
						ind += 1
						ct = 0
				else:
					if(ct == val and ind < k-1):
						ind += 1
						ct = 0
				if(a[i][j] == 'R'):
					ct += 1
				ans[i][j] = l[ind]
	#print(ans)
	for i in ans:
		print("".join(i))