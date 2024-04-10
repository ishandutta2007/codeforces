n, v = map(int, input().split())
if n <= v:
	print(n - 1)
else:
	ans = v
	for i in range(2, n - v + 1):
		ans += i
	print(ans)