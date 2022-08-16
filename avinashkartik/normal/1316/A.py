from math import *
t = int(input())
for y in range(t):
	n,k = map(int,input().split())
	a = list(map(int,input().split()))
	s = sum(a)
	print(min(k,s))