n = int(input())
a = [int(x) for x in input().split()]
d = {}
for x in a:
	if x in d:
		d[x] += 1
	else:
		d[x] = 1
kol = 0
kol1 = 0
for key in d:
	if d[key] == 1:
		kol += 1
	if d[key] > 2:
		kol1 += 1
if kol % 2 == 1 and kol1 == 0:
	print("NO")
	exit(0)
print("YES")
if kol % 2 == 0:
	ind = 0
	ind1 = 0
	for i in range(n):
		if d[a[i]] == 1:
			if ind == ind1:
				print('A',end = '')
				ind += 1
			else:
				print('B',end = '')
				ind1 += 1
		else:
			print('A', end = '')
else:
	ind = 0
	ind1 = 0
	f = True
	res = -1
	pic = ""
	for i in range(n):
		if d[a[i]] == 1:
			if ind == ind1:
				print('A', end = '')
				ind += 1
			else:
				print('B', end = '')
				ind1 += 1
		elif d[a[i]] > 2 and f:
			f = False
			res = a[i]
			if ind == ind1:
				print('A', end = '')
				ind += 1
				pic = 'B'
			else:
				print('B', end = '')
				ind1 += 1
				pic = 'A'
		else:
			if a[i] == res:
				print(pic, end = '')
			else:
				print('A', end = '')