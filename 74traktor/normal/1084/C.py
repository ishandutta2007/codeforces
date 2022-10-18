mod = int(1e9) + 7

s = input()
n = len(s)

ans = 1
kol = 0
tmp = 0
for c in s:
	if c == 'b':
		ans *= (kol + 1)
		ans = ans % mod
		kol = 0
	if c == 'a':
		kol += 1
		tmp += 1
print((ans * (kol + 1) - 1) % mod)