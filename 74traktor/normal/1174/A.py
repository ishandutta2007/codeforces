n = int(input())
a = [int(x) for x in input().split()]
x = a[0]
cnt = 0
for y in a:
	if y == x:
		cnt += 1
if cnt == 2 * n:
	print(-1)
else:
	a.sort()
	for x in a:
		print(x, end = ' ')