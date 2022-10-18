n = int(input())
a = [int(x) for x in input().split()]
imin = a[0]
imax = a[0]
kol_imin = 1
kol_imax = 1
for i in range(1, n):
	if a[i] > imax:
		imax = a[i]
		kol_imax = 1
	elif a[i] == imax:
		kol_imax += 1
	if a[i] < imin:
		imin = a[i]
		kol_imin = 1
	elif a[i] == imin:
		kol_imin += 1
if imax == imin:
	print(0, kol_imax * (kol_imax - 1) // 2)
else:
	print(imax - imin, kol_imin * kol_imax)