# map(int, raw_input().split())
# " ".join([])
# [0] * n
# isupper
from math import sqrt
n = input()
k = 1
while k * (k + 1) <= 2 * n:
	a = 1
	b = 1
	c = -2 * (n - k * (k + 1) / 2)
	if b * b - 4 * a * c >= 0:
		l = int((-b + sqrt(b * b - 4 * a * c)) / a) / 2
		if l > 0 and k * (k + 1) + l * (l + 1) == 2 * n:
			print "YES"
			exit(0)
	k += 1

		
print "NO"