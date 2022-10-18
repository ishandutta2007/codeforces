n = int(input())
i = 0
while (i + 1) * (i + 1) <= n:
	i += 1
print(2 * i + (n - i * i + i - 1) // i)