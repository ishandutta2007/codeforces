from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
mod = 10**9 + 7

t = int(input())
for y in range(t):
	n = int(input())
	n1 = n
	ans = 0
	ct = 0
	while(n >= 10):
		ans += 9
		#print(n%10)
		ct += 1;
		n = n//10
	m = n
	for i in range(ct):
		m *= 10
		m += n
	#print(m)
	ans += n
	if(n1 < m):
		ans -= 1
	print(ans)