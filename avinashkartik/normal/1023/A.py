from collections import *
from math import *

n,m = list(map(int,input().split()))
s = input()
t = input()
if(s.count('*') == 0):
	if(s == t):
		print("YES")
	else:
		print("NO")
else:
	ind = s.index('*')
	if(s[:ind] != t[:ind]):
		print("NO")
	else:
		no = n - (ind+1)
		if(m - no < ind):
			print("NO")
		else:
			if(s[n-no:] == t[m-no:]):
				print("YES")
			else:
				print("NO")