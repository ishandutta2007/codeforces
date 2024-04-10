import math

t = int(input())
for i in range(t):
	d = int(input())
	if d == 1:
		print('N')
	else:
		if d * d - 4 * d < 0:
			print('N')
		else:
			b = (d + math.sqrt(d * d - 4 * d)) / 2
			a = d - b
			if a >= 0 and b >= 0:
				print('Y', a, b)
			else:
				print('N')