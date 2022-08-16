from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
n = int(input())
a = list(map(int,input().split()))
m = 0
ct = 0
for i in range(n):
	#print(m,a[i])
	if(a[i] >= m and a[i] == i+1):
		ct += 1
		m = 0
	else:
		m = max(m,a[i])
print(ct)