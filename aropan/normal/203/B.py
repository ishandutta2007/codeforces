n, m = map(int, raw_input().split())
a = [[0] * (n + 3) for i in xrange(n + 3)]
for i in xrange(m):
	x, y = map(int, raw_input().split())
	for dx in range(3):
		for dy in range(3):
			a[x + dx][y + dy] += 1
			if a[x + dx][y + dy] == 9:
				print i + 1
				exit(0)
print -1