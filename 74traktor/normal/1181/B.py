n = int(input())
t = n // 2
s = input()
while s[t] == '0':
	t -= 1
k = n // 2 + 1
while k < len(s) and s[k] == '0':
	k += 1
ans1 = -1
ans2 = -1
if t > 0:
	ans1 = int(s[:t]) + int(s[t:])
if k < len(s):
	ans2 = int(s[:k]) + int(s[k:])
if ans1 == -1:
	print(ans2)
elif ans2 == -1:
	print(ans1)
else:
	print(min(ans1, ans2))