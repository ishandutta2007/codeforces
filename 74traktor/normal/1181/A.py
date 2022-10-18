x, y, z = map(int, input().split())
t = (x + y) // z
p = x // z
h = y // z
if t == p + h:
	print(t, 0)
else:
	print(t, min(z - x % z, z - y % z))