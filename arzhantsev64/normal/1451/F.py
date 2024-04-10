T = int(input())

for t in range(T):
	n, m = list(map(int, input().split()))
	min_has = 1e9
	min_xor = 0
	a = [list(map(int, input().split())) for i in range(n)]
	flag = False
	for s in range(n + m - 1):
		xor = 0
		for i in range(n):
			j = s - i
			if j < 0 or j >= m:
				continue
			if a[i][j] == 0:
				continue
			has = True
			xor ^= a[i][j]
		if xor != 0:
			flag = True
			break
	print('Ashish' if flag else 'Jeel')