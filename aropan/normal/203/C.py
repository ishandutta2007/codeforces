n, d = map(int, raw_input().split())
a, b = map(int, raw_input().split())
v = []
for i in xrange(n):
	x, y = map(int, raw_input().split())
	v.append((x * a + y * b, i))
v.sort()
ans = []
for e in v:
	d -= e[0]
	if d < 0:
		break
	ans.append(e[1] + 1)
print len(ans)
print " ".join(str(x) for x in ans)