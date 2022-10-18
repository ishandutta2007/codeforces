n = int(input())
if n == 1:
	print(1)
	print(1, 1)
	exit(0)
k = 1 + n // 2
print(1 + n // 2)
for i in range(k):
	if n > 0:
		n -= 1
		print(1, i + 1)
for i in range(1, k):
	if n > 0:
		n -= 1
		print(i + 1, k)