n = int(input())
s = input()
cnt = 0
t = (n - 11) // 2
for c in s:
	if c == '8':
		cnt += 1
if t >= cnt:
	print("NO")
	exit(0)
for i in range(n):
	if s[i] == '8':
		t -= 1
	if t == -1:
		if i <= (n - 11):
			print("YES")
		else:
			print("NO")
		exit(0)