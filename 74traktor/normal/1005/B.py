s = input()
t = input()
k = 0
if len(s) > len(t):
	k = len(s) - len(t)
	s = s[len(s) - len(t):len(s)]
elif len(t) > len(s):
	k = len(t) - len(s)
	t = t[len(t) - len(s):len(t)]
#print(s, t, k)
for i in range(len(s) - 1, -1, -1):
	if s[i] != t[i]:
		print(k + (i + 1) * 2)
		exit(0)
print(k)