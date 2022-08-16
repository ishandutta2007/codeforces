from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
  
n = int(input())
a = list(map(int,input().split()))
if(n == 1):
	print(a[0])
else:
	ans = 0
	for i in range(n):
		ans += abs(a[i])
	m = max(a)
	if(m < 0):
		ans += 2*m
	m = min(a)
	if(m > 0):
		ans -= 2*m
	print(ans)