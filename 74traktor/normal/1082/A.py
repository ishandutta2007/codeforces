t = int(input())
for i in range(t):
	n, x, y, d = map(int, input().split())
	if abs(x - y) % d == 0:
		print(abs(x - y) // d)
		continue
	dist1 = y - 1
	dist2 = n - y
	ans1 = int(1e18)
	ans2 = int(1e18)
	if dist1 % d == 0:
		ans1 = dist1 // d + (x + d - 2) // d
	if dist2 % d == 0:
		ans2 = dist2 // d + (n - x + d - 1) // d
	
	p = min(ans1, ans2)
	if  p == int(1e18):
		print(-1)
	else:
		print(p)