import math

n = int(input())
ans = []
for i in range(1, int(math.sqrt(n)) + 1):
	if n % i == 0:
		ans.append((n // i) * (n // i - 1) // 2 * i + n // i)
		if i * i != n:
			ans.append((i) * (i - 1) // 2 * (n // i) + i)
ans.sort()
for x in ans:
	print(x, end = ' ')