t = int(input())
for it in range(t):
	a, b = map(int, input().split())
	a -= b
	if a < 0:
		a = -a
	z = [5, 2, 1]
	ans = 0
	for i in z:
		ans += a // i
		a %= i
	print(ans)