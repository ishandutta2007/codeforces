from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
n = int(input())
a = list(map(int,input().split()))
ct = a.count(min(a))
if(ct > n//2):
	print("Bob")
else:
	print("Alice")