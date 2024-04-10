n, m = list(map(int, input().split()))
arr = [[0 for i in range(m)] for i in range(n)]
for i in range(n):
	arr[i] = list(map(int, input().split()))
ans = n * m
for i in range(n):
	c0 = 0
	c1 = 0
	for j in range(m):
		if arr[i][j] == 1:
			c1 += 1
		else:
			c0 += 1
	ans += max(0, 2 ** (c1) - c1 - 1)
	ans += max(0, 2 ** (c0) - c0 - 1)
for i in range(m):
	c0 = 0
	c1 = 0
	for j in range(n):
		if arr[j][i] == 1:
			c1 += 1
		else:
			c0 += 1
	ans += max(0, 2 ** (c1) - c1 - 1)
	ans += max(0, 2 ** (c0) - c0 - 1)
print(ans)