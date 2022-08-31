from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
mod = 10**9 + 7

t = int(input())
for y in range(t):
	a = input()
	n = len(a)
	i = 0
	ch = 0
	ans = []
	while(i<=n-3):
		if(a[i:i+3] == "one"):
			ch += 1
			ans.append(i+2)
			i += 3
		elif(a[i:i+3] == "two"):
			if(i <= n-5):
				if(a[i:i+5] == "twone"):
					ans.append(i+3)
				else:
					ans.append(i+2)
			else:
				ans.append(i+2)
			ch += 1
			i += 3
		else:
			i += 1
	print(ch)
	for i in ans:
		print(i,end = " ")
	print()