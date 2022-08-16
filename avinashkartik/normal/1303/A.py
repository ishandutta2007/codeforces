t = int(input())
for y in range(t):
	s = input()
	n = len(s)
	z = s.count('0')
	ctf = ctb = 0
	if(z == n):
		print(0)
		continue
	for i in range(n):
		if(s[i] == '1'):
			break
		ctf += 1
	for i in range(n-1,-1,-1):
		if(s[i] == '1'):
			break
		ctb += 1
	print(z-ctf-ctb)