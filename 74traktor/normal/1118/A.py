q = int(input())
for i in range(q):
	n, a, b = map(int, input().split())
	if n % 2 == 0:
		print(min(n * a, n // 2 * b))
	else:
		print(min(n * a, (n // 2) * b + a))