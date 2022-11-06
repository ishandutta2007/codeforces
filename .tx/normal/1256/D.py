t = int(input())
for it in range(t):
	n, k = map(int, input().split())
	a = list(input())
	o = 0
	for i in range(n):
		if a[i] == '1':
			o += 1
		else:
			if k >= o:
				a[i], a[i - o] = a[i - o], a[i]
				k -= o
			else:
				a[i], a[i - k] = a[i - k], a[i]
				break

	print("".join(a))