s = input()
n = len(s)
cnt = 0
for c in s:
	if c == 'a':
		cnt += 1
k = (n + 2) // 2
if cnt >= k:
	print(n)
else:
	print(cnt + cnt - 1)