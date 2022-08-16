from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
  
n = int(input())
a = list(map(int,input().split()))
pre = [0]
for i in range(n):
	pre.append(pre[-1]^a[i])
de = dict()
do = dict()
for i in range(n+1):
	if(i % 2 == 0):
		if pre[i] not in de:
			de[pre[i]] = 1
		else:
			de[pre[i]] += 1
	else:
		if pre[i] not in do:
			do[pre[i]] = 1
		else:
			do[pre[i]] += 1
ans = 0
for x in de.values(): 
	ans += x*(x-1)//2
for x in do.values(): 
	ans += x*(x-1)//2
print(ans)