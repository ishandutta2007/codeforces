from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
n = int(input())
for i in range(int(sqrt(n)),0,-1):
	if(n%i == 0 and gcd(n//i,i) == 1):
		print(i,n//i)
		break