n, k = map(int, input().split())
ans = 0
a=list(map(int, input().split()))
b = set()
a = [0] + a
n += 1
for i in range(1, n):
	a[i] += a[i-1]

t = 1
for z in range(100):
	if abs(t) <= 10 ** 16:
		b.add(t)
	t *= k

for x in b:
	d = dict()
	for i in a:
		ans += d.get(i-x, 0)
		d[i] = d.get(i, 0) + 1
print(ans)