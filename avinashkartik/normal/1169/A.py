from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
  
n,x,a,y,b = map(int,input().split())
x -= 1
y -= 1
a -= 1
b -= 1
while(x != a and y != b):
	x += 1
	x %= n
	y -= 1
	y %= n
	if(x == y):
		print("YES")
		break
else:
	print("NO")