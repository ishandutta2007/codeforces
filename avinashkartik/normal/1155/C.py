from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
n,m = map(int,input().split())
x = list(map(int,input().split()))
y = list(map(int,input().split()))
g = x[1]-x[0]
for i in range(1,n-1):
	g = gcd(g,x[i+1]-x[i])
for i in range(m):
	if(g%y[i] == 0):
		print("YES")
		print(x[0],i+1)
		break
else:
	print("NO")