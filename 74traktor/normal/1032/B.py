s = input()
n = len(s)
for i in range(1, 6):
	if (n + i - 1) // i <= 20:
		sim = n // i
		kol = (i - n % i) % i
		res = []
		j = 0
		#print(kol)
		print(i, (n + i - 1) // i)
		for j in range(kol):
			res.append(s[j * sim:j * sim + sim] + '*')
		j = kol * sim
		sim = (n + i - 1) // i
		for j in range(j, n, sim):
				res.append(s[j:j + sim])
		for rt in res:
			print(rt)
		exit(0)