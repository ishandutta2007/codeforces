from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
  
n,k = map(int,input().split())
s = input()
c = Counter(s)
m = 10**6
for i in range(k):
	ind = chr(i+65)
	if ind not in c:
		m = 0
	else:
		m = min(m,c[ind])
print(m*k)