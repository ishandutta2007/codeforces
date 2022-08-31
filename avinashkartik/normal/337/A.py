from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
n,m = map(int,input().split())
a = list(map(int,input().split()))
a.sort()
minn= a[n-1] - a[0]
for i in range(m-n+1):
	minn = min(minn,a[i+n-1] - a[i])
print(minn)