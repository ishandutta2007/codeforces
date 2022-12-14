n, m = map(int, input().split())

g = [set() for _ in range(n)]
l = []
p = [0 for _ in range(n)]

for _ in range(m):
	a, b = map(int, input().split())
	a -= 1
	b -= 1

	p[a] += 1
	p[b] += 1
	
	g[a].add(b)
	g[b].add(a)

	l.append((a, b))

ans = 100000

for i, j in l:
	for k in range(n):
		if k in g[i] and k in g[j]:
			ans = min(ans, p[i] + p[j] + p[k])

if ans == 100000:
	ans = -1
else:
	ans -= 6

print(ans)