n, m = map(int, input().split())
ans = 0
for i in range(n):
    a = list(map(int, input().split()))
    for j in range(m):
        ans += max(a[2 * j], a[2 * j+1])
print(ans)