t = int(input())
for y in range(t):
	n = int(input())
	a = list(map(int,input().split()))
	f = a[0]&1
	for i in a:
		if i&1 != f:
			print("NO")
			break
	else:
		print("YES")