n, k, t = list(map(int, input().split()))
if t <= k:
	print(t)
elif k < t <= n:
	print(k)
else:
	print(k - t + n)