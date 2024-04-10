n,a,b = map(int,input().split())
q = [int(x) for x in input().split()]
kol = 0
for i in range(n // 2 + n % 2):
	if q[i] == 0:
		if q[n - i - 1] == 1:
			print(-1)
			exit(0)
		elif q[n - i - 1] == 2:
			q[n - i - 1] = 0
			kol += a
	elif q[i] == 1:
		if q[n - i - 1] == 0:
			print(-1)
			exit(0)
		elif q[n - i - 1] == 2:
			kol += b
			q[n - i - 1] = 1
	else:
		if q[n - i - 1] == 0:
			kol += a
			q[i] = 0
		elif q[n - i - 1] == 1:
			kol += b
			q[i] = 1
		else:
			if i != n // 2:
				kol += 2 * (min(a,b))
			else:
				kol += min(a,b)

print(kol)