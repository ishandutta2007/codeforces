n = int(input())
matr = []
for i in range(n):
	s = input()
	matr.append(s)
row = [0] * n
col = [0] * n
for i in range(n):
	for j in range(n):
		if matr[i][j] == 'C':
			row[i] += 1
			col[j] += 1
ans = 0
for i in range(n):
	ans += row[i] * (row[i] - 1) // 2 + col[i] * (col[i] - 1) // 2
print(ans)