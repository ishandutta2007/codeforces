n, a, x, b, y = map(int, input().split())
while a != x and b != y:
	if a == b:
		print("YES")
		exit(0)
	a += 1
	if a == n + 1:
		a = 1
	b -= 1
	if b == 0:
		b = n
if a == b:
	print("YES")
else:
	print("NO")