n = int(input())
d = {}
for i in range(n):
	p = list(map(int, input().split()))
	if p[0] == 0:
		d[p[1]] = d.get(p[1], 0)
	else:
		if p[0] - d.get(p[1], -1) > 1:
			print("NO")
			exit()
		d[p[1]] = max(d[p[1]], p[0])
print("YES")