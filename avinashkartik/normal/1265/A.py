from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)

t = int(input())
for y in range(t):
	s = list(input())
	n = len(s)
	for i in range(n):
		if(s[i] == '?'):
			if(0 == n-1): s[i] = 'a'
			elif(i == 0):
				if(s[i+1] != 'a'):
					s[i] = 'a'
				elif(s[i+1] != 'b'):
					s[i] = 'b'
				else:
					s[i] = 'c'
			elif(i == n-1):
				if(s[i-1] != 'a'):
					s[i] = 'a'
				elif(s[i-1] != 'b'):
					s[i] = 'b'
				else:
					s[i] = 'c'
			else:
				if(s[i+1] != 'a' and s[i-1] != 'a'):
					s[i] = 'a'
				elif(s[i+1] != 'b' and s[i-1] != 'b'):
					s[i] = 'b'
				else:
					s[i] = 'c'
	flag = 0
	for i in range(1,n):
		if(s[i] == s[i-1]):
			flag = 1
			break
	if(flag == 1): print(-1)
	else: print("".join(s))