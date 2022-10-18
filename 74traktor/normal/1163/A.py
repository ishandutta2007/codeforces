n, m = map(int, input().split())
if m * 2 <= n:
	print(max(1, m))
else:
	if n % 2 == 0:
		print(n - m)
	else:
		k = m - n // 2
		if k <= 1:
			print(n // 2)
		else:
			k -= 2
			print(n // 2 - k - 1)