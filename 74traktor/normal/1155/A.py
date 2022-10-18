n = int(input())
s = input()
for i in range(len(s) - 1):
	if s[i] > s[i + 1]:
		print("YES")
		print(i + 1, i + 2)
		exit(0)
print("NO")