from math import *
from collections import *
test = int(input())
for y in range(test):
	n = int(input())
	n -= 1
	i = 1
	ans = []
	while(n > 0):
		if i*4 < n:
			ans.append(i)
			i *= 2
		elif i*3 <= n <= i*4:
			ans.append(n-i*3)
			i += n-i*3
		elif n > i*2:
			ans.append(0)
		else:
			ans.append(n-i)
			i += n-i
		n -= i
	print(len(ans))
	for i in ans:
		print(i,end = " ")
	print()