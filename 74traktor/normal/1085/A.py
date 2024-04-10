s = input()
if len(s) % 2 == 0:
	i = len(s) // 2 - 1
	j = len(s) // 2
	while i >= 0:
		print(s[i] + s[j], end = '')
		i -= 1
		j += 1
else:
	i = len(s) // 2 - 1
	j = len(s) // 2 + 1
	print(s[len(s) // 2], end = '')
	while i >= 0:
		print(s[j] + s[i], end = '')
		i -= 1
		j += 1