from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
  
s = input()
n = len(s)
ans = 0
for i in range(n):
	m = 10**6
	for k in range(1,5):
		for j in range(i,i+7):
			if(j + 2*k >= n):
				break
			if(s[j] == s[j+k] and s[j] == s[j+2*k]):
				m = min(m,j+2*k)
	if(m != 10**6):
		ans += n-m
print(ans)