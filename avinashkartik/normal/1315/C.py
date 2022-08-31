from math import *
from collections import *
t = int(input())
for y in range(t):
	n = int(input())
	a = list(map(int,input().split()))
	ch = [0 for i in range(2*n+1)]
	b = [-1 for i in range(2*n)]
	for i in range(n):
		ch[a[i]] = 1
		b[2*i] = a[i]
	flag = 0
	for i in range(0,2*n,2):
		m = -1
		for j in range(b[i],2*n+1):
			if(ch[j] == 0):
				ch[j] = 1
				m = j
				break
		if(m == -1):
			flag = -1
			break
		b[i+1] = m
		#print(ch)
	if(flag == -1):
		print(-1)
	else:
		for i in b:
			print(i,end = " ")
		print()