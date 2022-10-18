n = int(input())
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]
isi = [0] * n
d = {}
head = n
for i in range(len(b)):
	d[a[i]] = i 
res = []
head = 0
for i in range(n):
	if isi[b[i] - 1] == 0:
		ind = d[b[i]]
		kol = 0
		for j in range(head, ind + 1):
			isi[a[j] - 1] = 1
			kol += 1
		res.append(kol)
		head = ind + 1
	else:
		res.append(0)
for c in res:
	print(c, end = ' ')