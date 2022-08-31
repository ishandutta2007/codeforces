from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
n = int(input())
a = list(map(int,input().split()))
a.sort()
ct = 1
for i in a:
	if(i >= ct):
		ct += 1
print(ct-1)