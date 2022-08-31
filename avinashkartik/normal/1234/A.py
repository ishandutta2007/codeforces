from math import *
t = int(input())
for y in range(t):
	n = int(input())
	l = list(map(int,input().split()))
	s = sum(l)
	a = ceil(s/n)
	print(a)