from math import *
from collections import *
t = int(input())
for y in range(t):
	a,m = map(int,input().split())
	g = gcd(a,m)
	m1 = m//g
	i = 2
	ans = m1
	while(i*i <= m1):
		if(m1%i == 0):
			ans //= i
			ans *= (i-1)
		while(m1%i == 0): m1 //= i
		i += 1
	if(m1 > 1):
		ans //= m1
		ans *= (m1-1)
	print(ans)