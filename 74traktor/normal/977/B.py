n = int(input())
d = {}
s = input()
for i in range(n - 1):
	if (s[i] + s[i + 1]) in d:
		d[s[i] + s[i + 1]] += 1
	else:
		d[s[i] + s[i + 1]] = 1
imax = -1
ans = ""
for key in d:
	if d[key] > imax:
		imax = d[key]
		ans = key
print(ans)