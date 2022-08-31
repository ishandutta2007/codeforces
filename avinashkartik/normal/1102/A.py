from collections import *
from math import *

n = int(input())
ans = 0
if(n&1):
	n -= 1
	ans = 1
if(n%4 == 2):
	ans += 1
print(ans%2)