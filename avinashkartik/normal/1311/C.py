from math import *
from collections import *
t = int(input())
for y in range(t):
	n,m = map(int,input().split())
	s = input()
	a = list(map(int,input().split()))
	pre = [0 for i in range(n)]
	al = [0 for i in range(26)]
	pre[0] = m+1
	for i in a:
		pre[i] -= 1
	for i in range(1,n):
		pre[i] += pre[i-1]
	for i in range(n):
		ind = ord(s[i]) - ord('a')
		al[ind] += pre[i]
	for i in al:
		print(i,end = " ")
	print()