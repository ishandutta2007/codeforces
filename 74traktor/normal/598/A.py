t = int(input())
for i in range(t):
	n = int(input())
	ans = n * (n + 1) // 2
	st = 1
	while st <= n:
		ans -= 2 * st
		st *= 2
	print(ans)