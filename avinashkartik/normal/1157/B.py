from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
n = int(input())
s = list(input())
l = list(map(int,input().split()))
ind = n
for i in range(n):
	s[i] = int(s[i])
	if(ind == n and s[i] < l[s[i]-1]):
		ind = i
for i  in range(ind,n):
	if(s[i] <= l[s[i]-1]):
		s[i] = l[s[i]-1]
	else:
		break
for i in s:
	print(i,end = "")
print()