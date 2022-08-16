from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
  
n = int(input())
for y in range(n):
	x,y = map(int,input().split())
	if(x >= y):
		print(y)
		continue
	else:
		s = y//x
		#print("s : ",s)
		t = y%x
		ans = ((s+1)**2)*t
		if(t != 0):
			ans += (s**2)*((y-t*(s+1))//s)
		else:
			ans += (s**2)*x
		print(ans)