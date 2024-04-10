n, k = map(int, input().split())
a = [int(x) for x in input().split()]
isi = [0] * n
for i in range(n):
	if a[i] <= k:
		isi[i] = 1
	else:
		break
for i in range(n - 1, -1, -1):
	if a[i] <= k:
		isi[i] = 1
	else:
		break
kol = 0
for x in  isi:
	kol += x
print(kol)