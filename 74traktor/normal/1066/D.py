n, m, k = map(int, input().split())
a = [int(x) for x in input().split()]
i = n - 1
tec = k
res = 0
while i >= 0 and m > 0:
	if a[i] <= tec:
		tec -= a[i]
		res += 1
		i -= 1
	else:
		m -= 1
		tec = k
print(res)