def a():	
	n, v = list(map(int, input().split(" ")))
	d = []
	for i in range(n):
		d.append(list(map(int, input().split(" "))))
	d.sort()

	cur = 0
	nex = 0
	k = 0
	r = 0
	for i in range(d[-1][0] + 2):
		nex = 0
		p = v
		if k != n:
			while(d[k][0] < i):
				k += 1
				if k == n:
					break
		if k != n:
			while(d[k][0] == i):
				nex += d[k][1]
				k += 1
				if k == n:
					break
		r += min(p, cur)
		p -= min(p, cur)
		r += min(p, nex)
		cur = nex - min(p, nex)
	return r

print(a())