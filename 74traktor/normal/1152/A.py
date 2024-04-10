n, m = map(int, input().split())
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]
x = 0
y = 0
for c in a:
	if c % 2 == 0:
		x += 1
	else:
		y += 1
x1 = 0
y1 = 0
for c in b:
	if c % 2 == 0:
		x1 += 1
	else:
		y1 += 1
print(min(x, y1) +  min(y, x1))