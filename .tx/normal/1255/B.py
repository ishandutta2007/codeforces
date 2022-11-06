t = int(input())
for it in range(t):
	n, m = map(int, input().split())
	a = list(map(int, input().split()))
	if n == 2 or m < n:
		print(-1)
		continue
	m1 = 0
	m2 = 1
	if a[m1] > a[m2]:
		m1, m2 = m2, m1
	for i in range(2, n):
		if a[i] < a[m1]:
			m1, m2 = i, m1
		elif a[i] < a[m2]:
			m2 = i

	ans = sum(a) * 2 + (a[m1] + a[m2]) * (m - n)
	print(ans)
	for i in range(n):
		print(i + 1, (i + 1) % n + 1)
	for i in range(m - n):
		print(m1 + 1, m2 + 1)