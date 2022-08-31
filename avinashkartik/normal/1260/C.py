from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
  
n = int(input())
for y in range(n):
	r,b,k = map(int,input().split())
	lcm = r*b//gcd(r,b)
	r1 = lcm//r
	b1 = lcm//b
	#print(r1,b1)
	if(r1 > b1):
		s = (r1-1)/b1
	else:
		s = (b1-1)/r1
	#print(s)
	if(s > k-1):
		print("Rebel")
	else:
		print("Obey")