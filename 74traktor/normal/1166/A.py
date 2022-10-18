n = int(input())
a = [0] * 27
for i in range(n):
	s = input()
	a[ord(s[0]) - ord('a')] += 1
ans = 0
for i in range(26):
	t = a[i] // 2
	k = a[i] - t
	ans += t * (t - 1) // 2
	ans += k * (k - 1) // 2
print(ans)