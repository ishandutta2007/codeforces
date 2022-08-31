from collections import *
from math import *

N = int(5e5+5)
p = [0 for i in range(N)]
for i in range(2,N):
	if(p[i] == 0):
		for j in range(i*i,N,i):
			if(p[j] == 0): p[j] = i

n = int(input())
a = [1 for i in range(n+1)]
primes = []
ct = 0
for i in range(1,n+1):
	if p[i] == 0:
		ct += 1
		primes.append(i)
g = 2
dig = 2*g
lim = g*g
j = 2
m = ct
for i in range(ct+1,n+1):
	if(dig > lim or dig > n):
		g += 1
		dig = 2*g
		j = 2
		if p[g] == 0:
			lim = g*g
		else:
			lim = p[g]*g
	#print(i,g,dig,j)
	a[i] = g
	dig = g*primes[j]
	j += 1
for i in range(2,n+1):
	print(a[i],end=" ")
print()