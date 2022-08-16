from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
s = input()
n = len(s)
flag = 0
for i in range(n):
	ch = ord(s[i]) - ord('a')
	if(flag > ch):
		print("NO")
		break
	else:
		flag = ch
else:
	c = s.count('c')
	b = s.count('b')
	a = s.count('a')
	if(c == a or c == b) and c != 0 and a != 0 and b != 0:
		print("YES")
	else:
		print("NO")