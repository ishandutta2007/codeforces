a, b, c = map(int, input().split())
a += c
b += c
if a == b:
	print(a + b)
else:
	print(min(a, b) * 2 + 1)