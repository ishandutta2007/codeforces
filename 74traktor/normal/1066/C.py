n = int(input())
d = {}
matr = [0] * (2 * n + 1)
head = n - 1
tail = n
for i in range(n):
	st, n = input().split()
	n = int(n)
	if st == 'L':
		matr[head] = n
		d[n] = head
		head -= 1
	elif st == 'R':
		matr[tail] = n
		d[n] = tail
		tail += 1
	else:
		print(min(d[n] - head, tail - d[n]) - 1)