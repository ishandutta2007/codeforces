from collections import *
from math import *

n = int(input())
a = [['.' for i in range(n)] for j in range(n)]
ans = 0
for i in range(n):
	for j in range(n):
		if (i+j)%2 == 0:
			a[i][j] = 'C'
			ans += 1
print(ans)
for i in range(n):
	print("".join(a[i]))