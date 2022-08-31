from collections import *
te = int(input())
for y in range(te):
	n,d = map(int,input().split())
	a = list(map(int,input().split()))
	for i in range(d):
		for j in range(1,n):
			if(a[j] != 0):
				a[j-1] += 1
				a[j] -= 1
				break
	print(a[0])