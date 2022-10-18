n = int(input())
a = [int(x) for x in input().split()]
ans = 0
cnt = 0
for x in a:
	cur = x // 2
	if cur <= cnt:
		ans += cur
		cnt -= cur
		if x % 2 == 1:
			cnt += 1
	else:
		ans += cnt
		ans += (x - 2 * cnt) // 3
		cnt = (x - 2 * cnt) % 3
print(ans)