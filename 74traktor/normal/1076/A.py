n = int(input())
s = input()
for i in range(len(s) - 1):
	if s[i] > s[i + 1]:
		print(s[:i] + s[i + 1:len(s)])
		exit(0)
print(s[:len(s) - 1])