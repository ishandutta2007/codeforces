from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
m = int(input())
for y in range(m):
	n,t,a,b = map(int,input().split())
	c = list(map(int,input().split()))
	A = c.count(0)
	d = list(map(int,input().split()))
	l = []
	T = [0 for i in range(n)]
	aa = [A for i in range(n)]
	for i in range(n):
		l.append([d[i],c[i]])
	l.sort()
	for i in range(n):
		if(l[i][1] == 0):
			if(i == 0):
				T[i]=a
				aa[i] = A-1
			else:
				T[i]=T[i-1]+a
				aa[i] = aa[i-1]-1
		else:
			if(i == 0): T[i]=b
			else: T[i]=T[i-1]+b
			aa[i] = aa[i-1]
	#print(aa)
	ct = max(min(A,(l[0][0]-1)//a),0)
	for i in range(n):
		if(i == n-1):
			if(T[i] <= t):
				ct = max(ct,i+1)
		else:
			#print(l[i+1][0],T[i])
			if(T[i] < l[i+1][0]):
				ct1 = (l[i+1][0]-1-T[i])//a
				ct1 = min(ct1,aa[i])
				ct = max(ct,i+1+ct1)
		#print(ct)
	print(ct)