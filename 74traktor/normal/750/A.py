n, k = map(int, input().split())
l = 0
r = n + 1
while r - l > 1:
	m = (r + l) // 2
	if 5 * m * (m + 1) // 2 + k <= 240:
		l = m
	else:
		r = m
print(l)