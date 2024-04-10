x, y, z, t2, t1, t3 = map(int,input().split())
l = abs(z - x) * t1 + 2 * t3 + abs(y - x) * t1 + t3
r = t2 * abs(x - y)
if l <= r:
	print("YES")
else:
	print("NO")