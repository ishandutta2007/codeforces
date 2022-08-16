from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)

t = int(input())
for y in range(t):
	n = int(input())
	a = []
	for i in range(n):
		a.append(list(input()))
	
	ch = 0
	for i in range(n):
		key = 0
		for j in range(n):
			if(j == i): continue
			if(a[i] == a[j]):
				key = 1
				break
		if(key == 1):
			#print(a[i])
			for j in range(4):
				b = a[i][::]
				flag = 0
				for k in range(10):
					b[j] = str(k)
					if(b not in a):
						ch += 1
						a[i][::] = b
						flag = 1 
						break
				if(flag == 1):
					break
	print(ch)
	for i in a:
		print("".join(i))