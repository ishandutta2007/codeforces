from collections import *
from math import *

n = int(input())
s = list(input())
c0,c1,c2 = s.count('0'),s.count('1'),s.count('2')
ct = n//3
for i in range(n):
	if(c0 >= ct):
		break
	if(s[i] == '1' and c1 > ct):
		c0 += 1
		c1 -= 1
		s[i] = '0'
	if(s[i] == '2' and c2 > ct):
		c0 += 1
		c2 -= 1
		s[i] = '0'
for i in range(n):
	if(c1 >= ct):
		break
	if(s[i] == '2' and c2 > ct):
		c1 += 1
		c2 -= 1
		s[i] = '1'
for i in range(n-1,-1,-1):
	if(c2 >= ct):
		break
	if(s[i] == '0' and c0 > ct):
		c2 += 1
		c0 -= 1
		s[i] = '2'
	if(s[i] == '1' and c1 > ct):
		c2 += 1
		c1 -= 1
		s[i] = '2'
for i in range(n-1,-1,-1):
	if(c1 >= ct):
		break
	if(s[i] == '0' and c0 > ct):
		c1 += 1
		c0 -= 1
		s[i] = '1'
print("".join(s))