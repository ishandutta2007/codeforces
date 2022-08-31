from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
n = int(input())
if(n < 10):
	print(9)
	exit(0)
ans = 10
n += 1
while(n > 9):
	while(n%10 != 0):
		#print(n)
		ans += 1
		n += 1
	n //= 10
print(ans)