n = int(input())
l = list(map(int, input().split()))

ok = [False for _ in range(5000)]
ok[0] = True

for i in range(1, 5000):
	for j in l:
		if i - j >= 0 and ok[i - j]:
			ok[i] = True
			break
	else:
		print(i)
		break
else:
	print(-1)