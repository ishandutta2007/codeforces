from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
test = int(input())
for y in range(test):
	n,k = map(int,input().split())
	k -= 1
	s = list(input())
	t = ""
	for i in range(k):
		t += "()"
	for i in range(n//2-k):
		t += "("
	for i in range(n//2-k):
		t += ")"
	print(n)
	for i in range(n):
		j = i
		while(s[j] != t[i]):
			j += 1
		s[i],s[j] = s[j],s[i]
		print(i+1,j+1)