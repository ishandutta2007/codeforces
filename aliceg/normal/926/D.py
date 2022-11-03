a = [[3, 3, 4, 4, 3, 3], [3, 3, 4, 4, 3, 3], [2, 2, 3, 3, 2, 2], [2, 2, 3, 3, 2, 2], [1, 1, 2, 2, 1, 1], [1, 1, 2, 2, 1, 1]]
b = ["".join(input().split('-')) for i in range(6)]
ans = []
for i in range(6):
	for j in range(6):
		if b[i][j] == '.':
			ans.append([a[i][j], i, j])
ans.sort(reverse=True)
for i in range(6):
	for j in range(6):
		if i == ans[0][1] and j == ans[0][2]:
			print('P', end='')
		else:
			print(b[i][j], end='')
		if j == 1 or j == 3:
			print('-', end='')
	print('')