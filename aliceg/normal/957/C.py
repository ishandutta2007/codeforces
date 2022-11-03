n, u = map(int, input().split())
a = list(map(int, input().split()))
l, r = 0, 0
ans = -1
for i in range(n):
    r = max(l, r)
    while r < n - 1 and a[r + 1] - a[l] <= u:
        r += 1
    if r - l > 1 and a[r] - a[l] <= u:
        ans = max(ans, (a[r] - a[l + 1]) / (a[r] - a[l]))
    l += 1
print(ans)