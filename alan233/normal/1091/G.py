from random import *
import math

def gcd(a, b):
	if a == 0:
		return b
	else:
		return gcd(b % a, a)


n = int(input())
S = []
ans = []
for _ in range(50):
	x = randint(1, n - 1)
	print("sqrt %d" % (x * x % n))
	y = int(input())
	if x != y:
		if x > y:
			x, y = y, x
		S.append(y - x), S.append(n // (y - x))
while n != 1:
	p = n
	for i in range(len(S)):
		if gcd(p, S[i]) != 1:
			p = gcd(p, S[i])
	for i in range(len(S)):
		if S[i] % p == 0:
			S[i] = S[i] // p
	n = n // p
	ans.append(p)
print("!", len(ans), *ans)