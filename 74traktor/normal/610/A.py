n = int(input())
if n % 2 == 1:
	print(0)
	exit(0)
t = n // 2
if t % 2 == 0:
	print(t // 2 - 1)
else:
	print(t // 2)