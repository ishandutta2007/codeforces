n = int(input())
a = [int(x) for x in input().split()]
kol = 1
dl = 1
a.sort()
for i in range(1, n):
	if a[i] == a[i - 1]:
		dl += 1
	else:
		dl = 1
	kol = max(kol, dl)
print(kol)