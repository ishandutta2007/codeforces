from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)

a,b,c,d = map(int,input().split())
ans = []
flag = 0
while(a > 0):
	ans.append(0)
	a -= 1
	if(b > 0):
		ans.append(1)
		b -= 1
if(b < 0):
	flag = 1
while(b > 0):
	if(c > 0):
		ans.append(2)
		c -= 1
	ans.append(1)
	b -= 1
if(c < 0):
	flag = 1
while(c > 0):
	ans.append(2)
	c -= 1
	if(d > 0):
		ans.append(3)
		d -= 1
if(d != 0 or c != 0):
	if(d == 1):
		ans.insert(0,1)
		n = len(ans)
		for i in range(n-1,-1,-1):
			if(ans[i] == 1):
				ans[i] = 3
				break
	else:
		flag = 1
n = len(ans)
if(n > 1 and ans[n-1] == 1 and ans[n-2] == 1):
	ans.pop()
	ans.insert(0,1)
for i in range(n-1):
	if(abs(ans[i+1]-ans[i]) != 1):
		flag = 1
		break
#print(ans)
if(flag == 1):
	print("NO")
else:
	print("YES")
	for i in ans:
		print(i,end = " ")
	print()