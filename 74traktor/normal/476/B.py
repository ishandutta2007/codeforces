s = input()
s1 = input()
kol_p = 0
kol_m = 0
kol_p1 = 0
kol_m1 = 0
tmp = 0
for c in s:
	if c == '+':
		kol_p += 1
	else:
		kol_m += 1
for c in s1:
	if c == '+':
		kol_p1 += 1
	elif c == '-':
		kol_m1 += 1
	else:
		tmp += 1

#print(kol_p1, kol_p, kol_m, kol_m1)
if kol_p1 > kol_p or kol_m1 > kol_m:
	print(0.0)
	exit(0)

nado = kol_p - kol_p1
ans = 1
for i in range(tmp - nado + 1, tmp + 1):
	ans *= i
for i in range(1, nado + 1):
	ans //= i
print(ans / (2 ** tmp))