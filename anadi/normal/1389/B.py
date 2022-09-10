t = int(input())

for _ in range(t):
	n, k, z = [int(s) for s in input().split()]
	arr = [int(s) for s in input().split()]
	
	pref = [0] * (n + 1)
	for i in range(n):
		pref[i + 1] = pref[i] + arr[i]
	
	ans = pref[k + 1]
	z = min(z, k // 2)

	for t in range(1, z + 1):
		cand = pref[k + 1 - 2 * t]
		best = 0
		for i in range(k + 1 - 2 * t):
			best = max(best, arr[i] + arr[i + 1])
		ans = max(ans, cand + best * t)
	print(ans)