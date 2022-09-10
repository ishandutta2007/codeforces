t = int(input())

for i in range(t):
	n, k = map(int, input().split())
	cur = n

	for j in range(2, n):
		if n % j == 0:
			cur = j
			break
	
	n += cur
	k -= 1
	n += 2 * k
	print(n)