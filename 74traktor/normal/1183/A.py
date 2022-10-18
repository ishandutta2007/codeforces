n = int(input())
for i in range(n, n + 1000):
	s = str(i)
	summ = 0
	for c in s:
		summ += ord(c) - ord('0')
	if summ % 4 == 0:
		print(i)
		exit(0)