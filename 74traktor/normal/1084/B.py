n, s = map(int, input().split())
v = [int(x) for x in input().split()]
t = sum(v)
if sum(v) < s:
	print(-1)
	exit(0)
b = min(v)
kol = t - b * n
s -= kol
if s <= 0:
	print(b)
	exit(0)
tmp = (s + n - 1) // n
print(b - tmp)