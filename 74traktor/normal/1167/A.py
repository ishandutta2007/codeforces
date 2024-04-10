n = int(input())
for i in range(n):
	t = int(input())
	s = input()
	f = False
	for j in range(t):
		if s[j] == '8':
			if t - j >= 11:
				f = True
	if f:
		print("YES")
	else:
		print("NO")