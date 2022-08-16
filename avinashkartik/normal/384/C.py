from collections import *
from math import *

n = int(input())
a = list(map(int,input().split()))
ct0,res0 = 0,0
for i in range(n):
	if(a[i] == 1): ct0 += 1
	else: res0 += ct0
ct1,res1 = 0,0
for i in range(n-1,-1,-1):
	if(a[i] == 0): ct1 += 1
	else: res1 += ct1
print(min(res0,res1))