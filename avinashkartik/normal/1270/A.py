from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
t = int(input())
for y in range(t):
	n,a,b = map(int,input().split())
	s = list(map(int,input().split()))
	t = list(map(int,input().split()))
	if(max(s) > max(t)):
		print("YES")
	else:
		print("NO")