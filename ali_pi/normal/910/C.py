m = {}
f = {}
for c in "abcdefghij": 
	m[c] = f[c] = 0

n = input()
for _ in range(n):
	s = raw_input()
	l = len(s)
	f[ s[0] ] = 1
	for i, c in enumerate(s):
		m[c] += 10**(l-1-i)

ans = 0
d = 1
z = 1
for c, k in sorted(m.items(), key=lambda x: x[1], reverse=True):
	if z and not f[c]:
		z = 0
	else:
		ans += d * k
		d += 1

print(ans)