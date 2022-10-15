def divide(a):
	n = len(a)
	for i in xrange(1, n + 1):
		if n % i == 0 and a[:i] * (n / i) == a:
			yield a[:i]
a = raw_input()
b = raw_input()
print len(set(divide(a)) & set(divide(b)))