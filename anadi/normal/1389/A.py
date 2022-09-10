t = int(input())

for _ in range(t):
	l, r = [int(s) for s in input().split()]
	if r < l + l:
		print(-1, -1)
	else:
		print(l, l + l)