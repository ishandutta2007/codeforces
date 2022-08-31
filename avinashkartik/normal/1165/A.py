from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
n,x,y = map(int,input().split())
a = list(input())
a = a[::-1]
ct = 0
for i in range(y):
	if(a[i] == '1'):
		ct += 1
if(a[y] == '0'):
	ct += 1
for i in range(y+1,x):
	if(a[i] == '1'):
		ct += 1
print(ct)