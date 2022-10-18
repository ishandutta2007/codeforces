n, k = map(int,input().split())
a = [int(x) for x in input().split()]
res = 0
for i in range(1, n):
	s = a[i - 1] + a[i]
	q = s // k
	res += q

	if q == 0 and a[i - 1] != 0:
		res += 1
		a[i] = 0
	else:
		a[i] = a[i] - (q * k - a[i - 1])
res += (a[n - 1] + k - 1) // k
print(res)