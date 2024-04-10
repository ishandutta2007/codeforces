t = int(input())
for i in range(t):
	x = int(input())
	if x % 2 == 1:
		print((x - 3) // 2 + 1)
	else:
		print(x // 2)