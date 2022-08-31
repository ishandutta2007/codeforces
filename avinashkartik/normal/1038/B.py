from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
  
n = int(input())
a = ceil(n/2)
if(a == 1):
	print("No")
else:
	print("Yes")
	print(1,a)
	print(n-1,end = " ")
	for i in range(1,n+1):
		if(i == a): continue
		print(i,end = " ")
	print()