n = int(input())
a = [int(x) for x in input().split()]
t = 0
d1 = {}
use1 = {}
use = {}
for x in a:
	if x in d1:
		if use1[x] == n - x:
			t += (n - x)
			use1[x] = 0
		use1[x] += 1
	else:
		d1[x] = 0
		t += (n - x)
		use1[x] = 1

if n != t:
	print("Impossible")
else:
	print("Possible")
	d = {}
	cv = 1
	for x in a:
		if x in d:
			if use[d[x]] == n - x:
				d[x] = cv
				cv += 1
				use[d[x]] = 0
			use[d[x]] += 1
			print(d[x], end = ' ')
		else:
			d[x] = cv
			use[d[x]] = 1
			cv += 1
			print(d[x], end = ' ')