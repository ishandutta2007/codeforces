from collections import *
from math import *

t = int(input())
for y in range(t):
	a,b,k = list(map(int,input().split()))
	ans = 0
	if(k&1): ans = a
	ans += (k//2)*(a-b)
	print(ans)