from collections import *
a = []
for i in range(5):
	a.append(list(map(int,input().split())))
for i in range(5):
	for j in range(5):
		if(a[i][j] == 1):
			print(abs(i-2)+abs(j-2))