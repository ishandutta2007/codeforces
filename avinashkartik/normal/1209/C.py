t = int(input())
for y in range(t):
	n = int(input())
	s = list(input())
	for i in range(n):
		s[i] = ord(s[i]) - ord('0')
	a = [0 for i in range(n)]
	l = sorted(s)
	#print(s,l)
	ind = 0
	for i in range(n):
		#print(ind)
		if(s[i] == l[ind]):
			ind += 1
			a[i] = 1
	for i in range(n):
		if(ind >= n):
			break
		if(s[i] == l[ind]):
			ind += 1
			a[i] = 2
	if(len(set(a)) > 2):
		print('-')
	else:
		for i in range(n):
			print(a[i],end="")
	print()