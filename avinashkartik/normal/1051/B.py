from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
l,r = map(int,input().split())
print("YES")
for i in range(l,r+1,2):
	print(i,i+1)