from math import *
t = int(input())
l = [chr(ord('a')+i) for i in range(26)]
for y in range(t):
	n,a,b = map(int,input().split())
	s = ""
	for i in range(n):
		s += l[i%b]
	print(s)