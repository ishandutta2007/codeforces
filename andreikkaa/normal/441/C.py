n, m, k = list(map(int, input().split(" ")))

s = False

def nex(x, y, s):
	if (y == 1 or y == m) and s:
		return x + 1, y, False
	if x % 2:
		return x, y + 1, True
	return x, y - 1, True

xc = 1
yc = 1
for i in range(k - 1):
	print(2, end = " ")
	print(xc, yc, end = " ")
	xc, yc, s = nex(xc, yc, s)
	print(xc, yc)
	xc, yc, s = nex(xc, yc, s)

print(n * m - (k - 1) * 2, end = " ")
for i in range(n * m - (k - 1) * 2):
	print(xc, yc, end=" ")
	xc, yc, s = nex(xc, yc, s)