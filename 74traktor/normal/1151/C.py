mod = 1000000007
S = [0] * 70
S[0] = 1;
for i in range(1, 65):
	S[i] = S[i - 1] * 2

l, r = map(int, input().split())
lef = l;
i = 1
j = 1
st = 0;
f = True;
while (l > S[st]):
	l -= S[st]
	if (f):
		f = False
		i += S[st]
	else:
		f = True
		j += S[st]
	st += 1
lenn = (r - lef + 1)
ans = 0
if (f):
	f = False
	i += (l - 1)
	k = 2 * i - 1
	ll = lef - l + 1
	rr = ll + S[st] - 1
	if (r <= rr):
		print((k * lenn % mod + lenn * (lenn - 1) % mod) % mod)
		exit(0);
	i -= (l - 1)
	lenn = (rr - lef + 1)
	ans += k * lenn % mod + lenn * (lenn - 1) % mod
	ans %= mod
	lef = rr + 1
	i += S[st]
	st += 1
else:
	f = True
	j += (l - 1)
	k = 2 * j
	ll = lef - l + 1
	rr = ll + S[st] - 1;
	if (r <= rr):
		print((k * lenn % mod + lenn * (lenn - 1) % mod) % mod)
		exit(0)
	j -= (l - 1)
	lenn = (rr - lef + 1)
	ans += k * lenn % mod + lenn * (lenn - 1) % mod
	ans %= mod
	lef = rr + 1
	j += S[st]
	st += 1
while (lef <= r):
	if (f):
		k = 2 * i - 1
		rr = lef + S[st] - 1
		if (r <= rr):
			lenn = r - lef + 1;
			print((ans + k * lenn % mod + lenn * (lenn - 1) % mod) % mod)
			exit(0)
		lenn = (rr - lef + 1)
		ans = (ans + k * lenn % mod + lenn * (lenn - 1) % mod) % mod
		lef = rr + 1
		i += S[st]
		st += 1
		f = False
	else:
		k = 2 * j
		rr = lef + S[st] - 1
		if (r <= rr):
			lenn = r - lef + 1
			print((ans + k * lenn % mod + lenn * (lenn - 1) % mod) % mod)
			exit(0)
		lenn = (rr - lef + 1)
		ans = (ans + k * lenn % mod + lenn * (lenn - 1) % mod) % mod
		lef = rr + 1
		j += S[st]
		st += 1
		f = True
	#print(lef, ans)