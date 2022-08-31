from math import *
q = int(input())
for y in range(q):
	n = int(input())
	s = list(input())
	ind1 = -1
	ind2 = -1
	for i in range(n):
		if(s[i] == '1'):
			ind1 = i
			break
	for i in range(n-1,-1,-1):
		if(s[i] == '1'):
			ind2 = n - 1 - i
			break
	m = min(ind1,ind2)
	ans = 2*(n-m)
	if(ind1 == -1):
		print(n)
	else:
		print(ans)