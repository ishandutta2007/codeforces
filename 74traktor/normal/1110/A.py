b, k = map(int, input().split())
a = [int(x) for x in input().split()]
if b % 2 == 0:
	if a[k - 1] % 2 == 0:
		print("even")
	else:
		print("odd")
else:
	r = sum(a)
	if r % 2 == 0:
		print("even")
	else:
		print("odd")