a, b, c = map(int, input().split())
if c == min(a + 2, b + 1, c):
	print(3 * c - 3)
elif b == min(a + 1, b, c):
	print(3 * b)
else:
	print(3 * a + 3)