from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
print('a'*300)
n = int(input())
sys.stdout.flush()
if(n == 0):
	exit(0)
a = 300-n
print('b'*300)
n = int(input())
sys.stdout.flush()
if(n == 0):
	exit(0)
b = 300 - n
if(a == 0):
	print('b'*b)
	n = int(input())
	sys.stdout.flush()
	exit(0)
if(b == 0):
	print('a'*a)
	n = int(input())
	sys.stdout.flush()
	exit(0)
n1 = b
l = ['a' for i in range(a+b)]
for i in range(a+b):
	l[i] = 'b'
	print("".join(l))
	n = int(input())
	sys.stdout.flush()
	if(n == 0):
		exit(0)
	if(n < n1):
		n1 = n
	else:
		l[i] = 'a'