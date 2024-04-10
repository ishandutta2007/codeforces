n, h, m = map(int, input().split())
a = [h] * (n + 1)
for i in range(m):
	l, r, x = map(int, input().split())
	for j in range(l, r + 1):
		a[j] = min(a[j], x)
ans = 0
for i in range(1, n + 1):
	ans += a[i] * a[i]
print(ans)