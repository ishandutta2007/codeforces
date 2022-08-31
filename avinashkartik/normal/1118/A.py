from collections import *
from math import *

t = int(input())
for y in range(t):
	n,a,b = list(map(int,input().split()))
	b = min(b,2*a)
	ans = (n//2)*b + (n&1)*a
	print(ans)