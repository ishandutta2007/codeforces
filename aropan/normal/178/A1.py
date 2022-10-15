n = int(input())
a = map(int, raw_input().split())
ans = 0
for i in xrange(n - 1):
	ans += a[i]
	print ans
	x = 1
	while (i + x * 2 < n):
		x *= 2
	a[i + x] += a[i]