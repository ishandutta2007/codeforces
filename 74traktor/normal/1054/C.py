n = int(input())
l = [int(x) for x in input().split()]
r = [int(x) for x in input().split()]
a = [0] * n
for i in range(n):
	a[i] = n - (l[i] + r[i])
	if a[i] < 0:
		print("NO")
		exit(0)
for i in range(n):
	max_l = 0
	max_r = 0
	for j in range(i):
		if a[j] > a[i]:
			max_l += 1
	for j in range(i + 1, n):
		if a[j] > a[i]:
			max_r += 1
	if max_l != l[i] or max_r != r[i]:
		print("NO")
		exit(0)
print("YES")
for x in a:
	print(x, end = ' ')