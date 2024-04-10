n = input()
a = raw_input()
g = [[0] * (n + 1) for i in xrange(2 * n + 1)]
f = [[0] * (n + 1) for i in xrange(2 * n + 1)]
for i in reversed(xrange(2 * n)):
	for j in xrange(n + 1):
		if j > 0:
			f[i][j] = max(f[i][j], f[i + 1][j - 1] + int(a[i]) * (10 ** (j - 1)))
		if 2 * n - i - j > 0:
			f[i][j] = max(f[i][j], f[i + 1][j] + int(a[i]) * (10 ** (2 * n - i - j - 1)))
i, j, o  = 0, n, ''
while i < 2 * n:
	if j > 0 and f[i][j] == f[i + 1][j - 1] + int(a[i]) * (10 ** (j - 1)):
		o += 'H'
		j -= 1
	else:
		o += 'M'
	i += 1
print (o)