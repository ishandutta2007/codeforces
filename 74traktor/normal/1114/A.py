x, y, z = map(int, input().split())
a, b, c = map(int, input().split())
a -= x
if a < 0:
	print("NO")
	exit(0)
if a + b < y:
	print("NO")
	exit(0)
if a + b + c - y < z:
	print("NO")
	exit(0)
print("YES")