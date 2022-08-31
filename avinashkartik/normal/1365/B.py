from math import *
t = int(input())
for y in range(t):
	n = int(input())
	a = list(map(int,input().split()))
	b = list(map(int,input().split()))
	if(a == sorted(a)):
		print("Yes")
		continue
	o = b.count(1)
	z = b.count(0)
	if(o > 0 and z > 0):
		print("Yes")
	else:
		print("No")