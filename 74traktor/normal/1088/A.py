x = int(input())
if x == 1:
	print(-1)
	exit(0)
x = (x + 2) // 2
if x % 2 == 1:
	x += 1
print(x, 2)