n, s = map(int, input().split())
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]

if a[0] == 0:
	print("NO")
	exit(0)

if a[s - 1] == 1:
	print("YES")
	exit(0)
if b[s - 1] == 0:
	print("NO")
	exit(0)
for j in range(s, n):
	if a[j] == b[j] and a[j] == 1:
		print("YES")
		exit(0)
print("NO")