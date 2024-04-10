n = int(input())
for i in range(n):
	s = input()
	mal = []
	bol = []
	cif = []
	for i in range(len(s)):
		if s[i] >= 'a' and s[i] <= 'z':
			mal.append(i)
		if s[i] >= 'A' and s[i] <= 'Z':
			bol.append(i)
		if s[i] >= '0' and s[i] <= '9':
			cif.append(i)
	if len(mal) > 0 and len(bol) > 0 and len(cif) > 0:
		print(s)
	elif len(mal) > 0 and len(bol) > 0:
		if len(mal) > 1:
			print(s[:mal[0]] + '1' + s[mal[0] + 1:])
		else:
			print(s[:bol[0]] + '1' + s[bol[0] + 1:])
	else:
		if len(mal) > 0 and len(cif) > 0:
			if len(mal) > 1:
				print(s[:mal[0]] + 'A' + s[mal[0] + 1:])
			else:
				print(s[:cif[0]] + 'A' + s[cif[0] + 1:])
		elif len(bol) > 0 and len(cif) > 0:
			if len(bol) > 1:
				print(s[:bol[0]] + 'a' + s[bol[0] + 1:])
			else:
				print(s[:cif[0]] + 'a' + s[cif[0] + 1:])
		else:
			if len(mal) > 0:
				print("1A" + s[2:])
			elif len(bol) > 0:
				print("1a" + s[2:])
			else:
				print("aA" + s[2:])