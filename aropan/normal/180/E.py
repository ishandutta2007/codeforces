import string
n, m, k = [int(x) for x in string.split(raw_input(), ' ')]
a = [int(x) for x in string.split(raw_input(), ' ')]
last = [n] * (m + 1)
next = [0] * (n + 1)
i = len(a)
while i > 0:
	i -= 1
	next[i] = last[a[i]]
	last[a[i]] = i
c = [0] * (m + 1)
l = [-1] * (m + 1)
i = 0
ans = 0
while i < n:
	x = a[i]
	if l[x] <= i:
		c[x] = 0
		l[x] = i
	while l[x] < n and l[x] - i - c[x] <= k:
		l[x] = next[l[x]]
		c[x] += 1
	ans = max(c[x], ans);
	c[x] -= 1
	i += 1
print ans