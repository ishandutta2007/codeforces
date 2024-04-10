t = input()
n = len(t)
pref = [0] * n
pred = 0
for i in range(n):
	if t[i] == 'a':
		pref[i] += 1
	pref[i] += pred
	pred = pref[i]
for i in range(n):
	if pref[n - 1] - pref[i] == 0:
		if i - pref[i] + 1 == n - i - 1:
			f = True
			uk1 = 0
			uk2 = i + 1
			while uk2 < n:
				while t[uk1] == 'a':
					uk1 += 1
				if t[uk1] != t[uk2]:
					f = False
					break
				uk1 += 1
				uk2 += 1
			if f:
				for j in range(i + 1):
					print(t[j], end = '')
				exit(0)
print(":(")