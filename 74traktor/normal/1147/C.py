n = int(input())
a = [int(x) for x in input().split()]
imin = a[0]
cnt = 0
for x in a:
	if x < imin:
		imin = x
		cnt = 0
	if x == imin:
		cnt += 1
if cnt <= n // 2:
	print("Alice")
else:
	print("Bob")