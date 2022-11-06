import sys

inp = sys.stdin

n = int(inp.readline())
after = [-1] * (10 ** 6 + 1)
before = [-1] * (10 ** 6 + 1)
used = [0] * (10 ** 6 + 1)

for i in range(n):
	x, y = map(int, inp.readline().split())
	after[x] = y
	before[y] = x
	used[x] = used[y] = 1

ans = [0] * n
i = 1
x = 0
while after[x] > 0:
	x = after[x]
	ans[i] = x
	i += 2

for i in range(10 ** 6 + 1):
	if used[i] == 1 and before[i] == -1:
		x = i
		break

i = 0
while (i < n) and (x > 0):
	ans[i] = x
	i += 2
	x = after[x]

for i in ans:
	print(i, end=' ')