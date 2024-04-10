t = []
l = []
r = []
for _ in range(input()):
	s, g = map(int, raw_input().split())
	t.append(s)
	l.append(s)
	r.append(g + s)
for i in range(1, len(l)):
	if l[i] < l[i - 1]:
		l[i] = l[i - 1] - 1
	if r[i] > r[i - 1]:
		r[i] = r[i - 1] + 1	
for i in range(len(l) - 2, -1, -1):
	if l[i] < l[i + 1]:
		l[i] = l[i + 1] - 1
	if r[i] > r[i + 1]:
		r[i] = r[i + 1] + 1
if [1 for a, b in zip(l, r) if a > b]:
	print(-1)
else:
	print(sum([b - a for a, b in zip(t, r)]))
	print(' '.join(map(str, r)))