t = int(input())
for i in range(t):
	n, k = map(int, input().split())
	for j in range(n):
		print(chr(ord('a') + j % k), end = '')
	print()