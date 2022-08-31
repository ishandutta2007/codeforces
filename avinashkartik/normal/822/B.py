from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
  
n,m = map(int,input().split())
s = input()
t = input()
l = [0 for i in range(10000)]
for i in range(m-n+1):
	r = []
	for j in range(n):
		if(t[i+j] != s[j]):
			r.append(j+1)
	if(len(r) < len(l)):
		l = r[::]
print(len(l))
for i in l:
	print(i,end = " ")