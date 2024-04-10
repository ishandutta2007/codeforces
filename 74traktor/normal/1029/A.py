n, k = map(int, input().split())
s = input()
i = n - 2
while i > -1:
	if s[:i + 1] == s[len(s) - i - 1:len(s)]:
		break
	i -= 1
if i == -1:
	print(s * k)
else:
	print(s, end = '')
	print(s[i + 1:len(s)] * (k - 1))