n, m = map(int,input().split())
imin = max(0,n - 2 * m)
s = 0
k = 1
while s < m:
	s = (k * (k - 1) // 2)
	k += 1
print(imin, n - k + 1)