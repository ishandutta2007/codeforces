from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
n = int(input())
a = list(map(int,input().split()))
l = [[] for i in range(105)]
for i in range(n):
	l[a[i]].append(i)
ans = [0 for i in range(n)]
ct = 0
f = 'A'
for i in range(105):
	if(len(l[i]) == 1):
		ans[l[i][0]] = f
		if(f == 'A'):
			f = 'B'
			ct += 1
		else:
			f = 'A'
			ct -= 1
flag = 0
if(ct == 1):
	for i in range(105):
		if(len(l[i]) > 2):
			ans[l[i][0]] = f
			break
	else:
		flag = 1
if(flag == 1):
	print("NO")
else:
	print("YES")
	for i in range(n):
		if(ans[i] == 0):
			ans[i] = 'A'
	print("".join(ans[:n]))