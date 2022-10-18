n, k = map(int, input().split())
a = [int(x) for x in input().split()]
a.sort()
l = 0
r = int(1e9)
while r - l > 1:
	m = (r + l) // 2
	l1 = -1
	r1 = len(a)
	while r1 - l1 > 1:
		m1 = (r1 + l1) // 2
		if a[m1] <= m:
			l1 = m1
		else:
			r1 = m1
	if l1 + 1 < k:
		l = m
	else:
		r = m
m = r
l1 = -1
r1 = len(a)
while r1 - l1 > 1:
	#print(l1, r1)
	m1 = (r1 + l1) // 2
	if a[m1] <= m:
		l1 = m1
	else:
		r1 = m1
if (l1 + 1) == k:
	print(m)
else:
	print(-1)