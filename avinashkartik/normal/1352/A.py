t = int(input())
for y in range(t):
	n = input()
	ans = []
	m = len(n)
	for i in range(m):
		if n[i] != '0':
			ans.append(int(n[i])*pow(10,m-i-1))
	print(len(ans))
	print(*ans)