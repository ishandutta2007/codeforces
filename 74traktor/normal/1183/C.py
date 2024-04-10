q = int(input())
for i in range(q):
	k, n, a, b = map(int, input().split())
	if n * b >= k:
		print(-1)
		continue
	l = 0
	r = min(k // a + 1, n + 1)
	while r - l > 1:
		m = (r + l) // 2
		if ((k - a * m - 1) // b >= n - m) and k - a * m > 0:
			l = m
		else:
			r = m
	print(l)