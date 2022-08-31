from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
  
n = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
a.sort()
b.sort()
na = n
nb = n
asum = 0
bsum = 0
for i in range(n):
	if(nb == 0):
		asum += a[-1]
		a.pop()
		na -= 1
	elif(na >= 1 and a[-1] > b[-1]):
		asum += a[-1]
		a.pop()
		na -= 1
	else:
		b.pop()
		nb -= 1

	if(na == 0):
		bsum += b[-1]
		b.pop()
		nb -= 1
	elif(nb >= 1 and a[-1] < b[-1]):
		bsum += b[-1]
		b.pop()
		nb -= 1
	else:
		a.pop()
		na -= 1
print(asum-bsum)