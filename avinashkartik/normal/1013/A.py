from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
n = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
if(sum(b) > sum(a)):
	print("No")
else:
	print("Yes")