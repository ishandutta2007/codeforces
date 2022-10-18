n = int(input())
a = [int(x) for x in input().split()]
imin = int(1e9)
for x in range(1, n + 1):
	suma = 0
	for j in range(n):
		t = j + 1
		suma += 2 * a[j] * ((x - 1) + j + abs(t - x))
	imin = min(imin, suma)
print(imin)