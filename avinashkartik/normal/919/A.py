from collections import *
from math import *

n,m = map(int,input().split())
ans = 1e17
for i in range(n):
	x,b = map(int,input().split())
	ans = min(ans,m/b*x)
print(ans)