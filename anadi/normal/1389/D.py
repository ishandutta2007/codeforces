t = int(input())

for _ in range(t):
	n, k = [int(s) for s in input().split()]
	ans = 0
	
	l1, r1 = [int(s) for s in input().split()]
	l2, r2 = [int(s) for s in input().split()]
	
	if r1 > r2:
		l1, l2, r1, r2 = l2, l1, r2, r1
	
	initial_k = max(0, (r1 - max(l1, l2)))
	k -= initial_k * n
	
	if(k < 0):
		print(0)
		continue
	
	in_cost = max(0, max(l1, l2) - r1)
	one_cost = r2 - min(l1, l2) - initial_k
	
	ans = 2 * k + in_cost
	for i in range(1, n + 1):
		cand = in_cost * i
		if one_cost * i >= k:
			cand += k
		else:
			cand += 2 * k - one_cost * i
		ans = min(ans, cand)
	print(ans)