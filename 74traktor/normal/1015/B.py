n = int(input())
s = input()
t = input()
a = []
i = 0
while i < n:
	j = i
	while j < n and s[j] != t[i]:
			j += 1
	if j == n:
		print(-1)
		exit(0)
	else:
		s = s[:i] + s[j] + s[i:j] + s[j + 1:n]
		for q in range(j - 1,i - 1,-1):
			a.append(q)
	i += 1
print(len(a))
for x in a:
	print(x + 1,end = ' ')