from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
n = int(input())
a = list(input())
t = []
i = 0
while(i < n-1):
	while(i < n-1 and a[i+1] == a[i]):
		i += 1
	if(i < n-1):
		t.append(a[i])
		t.append(a[i+1])
	i += 2
l = len(t)
print(n-l)
print("".join(t))