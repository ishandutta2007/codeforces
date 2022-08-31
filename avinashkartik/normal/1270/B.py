from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
t = int(input())
for y in range(t):
	n = int(input())
	a = list(map(int,input().split()))
	for i in range(n-1):
		if(abs(a[i+1]-a[i]) > 1):
			print("YES")
			print(i+1,i+2)
			break
	else:
		print("NO")