from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
n,x = map(int,input().split())
a = list(map(int,input().split()))
b = [a[i]&x for i in range(n)]
da = dict()
db = dict()
flag = -1
for i in a:
	if(i not in da):
		da[i] = 1
	else:
		print(0)
		exit(0)
for i in range(n):
	if(b[i] in da and a[i] != b[i]):
		print(1)
		exit(0)
	if(b[i] not in db):
		db[b[i]] = 1
	else:
		flag = 2
print(flag)