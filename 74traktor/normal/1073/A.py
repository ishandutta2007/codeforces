n = int(input())
s = input()
for i in range(1, n):
	if s[i] != s[i - 1]:
		print("YES")
		print(s[i - 1] + s[i])
		exit(0)
print("NO")