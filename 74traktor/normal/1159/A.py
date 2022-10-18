n = int(input())
s = input()
ans = 10000
for i in range(0, 105):
	f = True
	x = i
	for c in s:
		if c == '-':
			x -= 1
		else:
			x += 1
		if x < 0:
			f = False
	if f:
		ans = min(ans, x)
print(ans)