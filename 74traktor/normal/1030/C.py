n = int(input())
s = input()
for i in range(901):
	j = 0
	summa = 0
	f = True
	q = 0
	while j < n and f:
		summa += int(s[j])
		if summa > i:
			f = False
		elif summa == i:
			q += 1
			summa = 0
		j += 1
	if summa == 0 and f and q > 1:
		print("YES")
		exit(0)
print("NO")