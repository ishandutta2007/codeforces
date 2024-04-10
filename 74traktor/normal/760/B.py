n, m, k = map(int, input().split())
l = 0
r = int(1e12)
while r - l > 1:
	x = (r + l) // 2
	if x >= k:
		sum1 = x * (k - 1) - k * (k - 1) // 2
	else:
		t = x - 1
		sum1 = t * x - t * (t + 1) // 2 + k - 1 - t
	k1 = n - k + 1
	if x >= k1:
		 sum2 = x * (k1 - 1) - k1 * (k1 - 1) // 2
	else:
		t = x - 1
		sum2 = t * x - t * (t + 1) // 2 + k1 - 1 - t
	#print(l, r, x, sum1, sum2) 
	if sum1 + sum2 + x <= m:
		l = x
	else:
		r = x
print(l)