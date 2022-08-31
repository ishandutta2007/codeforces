from collections import *
from math import *
t = int(input())
for y in range(t):
	n = int(input())
	a = list(map(int,input().split()))
	b = list(map(int,input().split()))
	ch = [[0,0] for i in range(n)]
	for i in range(1,n):
		ch[i][0] = ch[i-1][0]
		ch[i][1] = ch[i-1][1]
		if(a[i-1] == 1):
			ch[i][1] += 1
		elif(a[i-1] == -1):
			ch[i][0] += 1
	for i in range(n-1,-1,-1):
		if(a[i] == b[i]):
			continue
		elif(a[i] < b[i]):
			if(ch[i][1] == 0):
				print("NO")
				break
		else:
			if(ch[i][0] == 0):
				print("NO")
				break
	else:
		print("YES")