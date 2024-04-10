n = int(input())
b = [int(x) for x in input().split()]
a = [0]
c = [b[0]]
for i in range(1, n // 2):
	if b[i] == b[i - 1]:
		a.append(a[len(a) - 1])
		c.append(c[len(c) - 1])
	elif b[i] > b[i - 1]:
		razn = (b[i] - b[i - 1])
		a.append(a[len(a) - 1] + razn)
		c.append(c[len(c) - 1])
	else:
		razn = (b[i - 1] - b[i])
		c.append(c[len(c) - 1] - razn)
		a.append(a[len(a) - 1])
for x in a:
	print(x, end = ' ')
for j in range(len(c) - 1, -1, -1):
	print(c[j], end = ' ')