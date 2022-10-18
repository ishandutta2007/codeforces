q = int(input())
for i in range(q):
	l1, r1, l2, r2 = map(int, input().split())
	f = False
	for j in range(l1, min(r1 + 1, l1 + 3)):
		for z in range(l2, min(r2 + 1, l2 + 4)):		
			if f == False and j != z:
				print(j, z)
				f = True