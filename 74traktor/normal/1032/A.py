n, k = map(int, input().split())
a = [int(x) for x in input().split()]
d = {}
for x in a:
	if x in d:
		d[x] += 1
	else:
		d[x] = 1
		
mnk = 0
k1 = len(d)
c = []
for key in d:
	c.append(d[key])
	mnk = max(mnk, (d[key] + k - 1) // k)
print(max(0,mnk * len(d) * k - len(a)))