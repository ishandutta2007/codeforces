from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
  
n = int(input())
for y in range(n):
	x,y = map(int,input().split())
	if(x == 0 and y == 0):
		print("Yes")
	elif(x*2 < y or y*2 < x):
		print("No")
	elif((x+y) % 3 == 0):
		print("Yes")
	else:
		print("No")