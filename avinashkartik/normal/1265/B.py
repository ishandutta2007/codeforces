from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)

t = int(input())
for y in range(t):
	n = int(input())
	a = list(map(int,input().split()))
	ans = ['1']
	le = 1
	l = a.index(1)
	l -= 1
	r = l + 2
	m = 1
	while(le < n):
		if(l != -1 and r != n):
			if(a[l] > a[r]):
				m = max(m,a[r])
				r += 1
				if(m == le+1):
					ans.append('1')
				else:
					ans.append('0')
			else:
				m = max(m,a[l])
				l -= 1
				if(m == le+1):
					ans.append('1')
				else:
					ans.append('0')
		elif(l != -1):
			m = max(m,a[l])
			l -= 1
			if(m == le+1):
				ans.append('1')
			else:
				ans.append('0')
		else:
			m = max(m,a[r])
			r += 1
			if(m == le+1):
				ans.append('1')
			else:
				ans.append('0')
		le += 1
	print("".join(ans))