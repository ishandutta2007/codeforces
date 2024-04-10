from fractions import*
n, m = map(int,raw_input().split())
x = 0
l = []
i = 1
while x < m and i <= n:
	j = i+1
	while x < m and j <= n:
		if gcd(i, j) == 1:
			x += 1
			l.append([i, j])
		j += 1
	i += 1
if n-1 <= len(l) == m:
	print "Possible"
	for p in l:
		print p[0], p[1]
else:
	print "Impossible"