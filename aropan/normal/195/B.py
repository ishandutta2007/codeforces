m, n = map(int, raw_input().split())
x = 0
for i in xrange(m):
	if x == 0:
		x = (n + 1) / 2
	print x
	if x < n - x + 1:
		x = n - x + 1
	else:
		x = n - x