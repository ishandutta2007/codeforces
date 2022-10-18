n, k = map(int, input().split())
a = [int(x) for x in input().split()]
l = 0
r = 1001
while r - l > 0.0000001:
	m = (r + l) / 2;
	plus = 0
	minus = 0
	for i in range(n):
		if a[i] <= m:
			plus += m - a[i]
		else:
			minus += a[i] - m
	minus = minus * (100 - k) / 100
	if minus >= plus:
		l = m
	else:
		r = m
print(l)