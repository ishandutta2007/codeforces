n, m, r = map(int, input().split())
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]
mx = 0
ans = r
for x in a:
	ans = max(ans, r // x * max(b) + r % x)
print(ans)