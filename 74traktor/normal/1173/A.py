x, y, z = map(int, input().split())
x -= y
if x < 0:
	x += z
	if x >= 0:
		print('?')
	else:
		print('-')
elif x == 0:
	if z == 0:
		print(0)
	else:
		print('?')
else:
	x -= z
	if x > 0:
		print('+')
	else:
		print('?')