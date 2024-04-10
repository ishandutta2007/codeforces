import sys
t = int(sys.stdin.readline())
for _ in range(t):
	n = int(sys.stdin.readline())
	a = []
	b = []

	for _ in range(n * 2):
		x, y = list(map(int, sys.stdin.readline().split()))
		if x == 0:
			b.append(y * y)
		else:
			a.append(x * x)

	a.sort()
	b.sort()

	d = 0
	for i in range(n):
		d = d + (a[i] + b[i]) ** 0.5
	print(d)