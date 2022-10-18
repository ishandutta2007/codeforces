n = int(input())
a = [int(x) for x in input().split()]
a.sort()
ans = 0
for i in range(0, n, 2):
	ans += (a[i + 1] - a[i])
print(ans)