x = int(input())
for n in xrange(1, 1000):
	if x == 3 and n == 3:
		continue
	if n % 2 == 0:
		if x % 4 == 0 and x <= (((n / 2 - 1)**2 + 1) / 2):
			print n
			break
	else:
		if x <= (n * n + 1) / 2:
			print n
			break