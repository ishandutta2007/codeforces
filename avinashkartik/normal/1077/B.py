from collections import *
from math import *

n = int(input())
a = list(map(int,input().split()))
ct = 0
for i in range(1,n-1):
	if(a[i] == 0 and a[i-1] == 1 and a[i+1] == 1):
		a[i+1] = 0
		ct += 1
print(ct)