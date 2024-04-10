s = input()
k = int(input())
r = 0
r1 = 0
for c in s:
	if c == '?':
		r += 1
	if c == '*':
		r1 += 1

t = len(s) - r - r1
if t == k:
	for c in s:
		if c != '?' and c != '*':
			print(c, end = '')
	exit(0)
if t < k:
	if r1 != 0:
		f = True
		for i in range(len(s)):
			if s[i] == '*':
				if f:
					f = False
					print(s[i - 1] * (k - t), end = '')
			elif s[i] != '?':
				print(s[i], end = '')				
		exit(0)
	else:
		print("Impossible")
else:
	if t - (r + r1) > k:
		print("Impossible")
	else:
		kol = t - k
		ans = ""
		for i in range(len(s)):
			if s[i] == '?':
				if kol > 0:
					ans = ans[:len(ans) - 1]
					kol -= 1
			elif s[i] == '*':
				if kol > 0:
					ans = ans[:len(ans) - 1]
					kol -= 1
			else:
				ans += s[i]
		print(ans)