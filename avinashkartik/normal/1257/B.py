from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
t = int(input())
for y in range(t):
	x,y = map(int,input().split())
	if(x == y):
		print("YES")
	elif(x > 3):
		print("YES")
	elif(x == 1):
		print("NO")
	elif(y <= 3):
		print("YES")
	else:
		print("NO")