a = raw_input()
b = raw_input()
c = {}
for i in xrange(26):
	c[chr(i + 97)] = 0
for i in xrange(len(a)):
	c[a[i]] += 1
pref = ''
ans = chr(255)
for i in xrange(min(len(a), len(b))):
	j = chr(ord(b[i]) + 1)
	while j <= 'z' and c[j] == 0:
		j = chr(ord(j) + 1)
	if j <= 'z':
		suff = j
		c[j] -= 1
		for ch, num in sorted(c.iteritems()):
			suff += ch * num
		c[j] += 1
		ans = pref + suff
	if c[b[i]] == 0:
		break;
	pref += b[i]
	c[b[i]] -= 1

if pref == b and len(b) < len(a):
	ans = pref
	for ch, num in sorted(c.iteritems()):
		ans += ch * num

if ans == chr(255):
	ans = -1
print ans