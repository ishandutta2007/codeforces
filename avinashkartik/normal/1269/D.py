from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
n = int(input())
a = list(map(int,input().split()))
ctw = ctb = 0
for i in range(n):
	if(i%2 == 0):
		ctw += a[i]//2
		ctb += a[i]-a[i]//2
	else:
		ctb += a[i]//2
		ctw += a[i]-a[i]//2
print(min(ctb,ctw))