n, a, b, c, d = map(int, input().split())
ans= 0
for x in range(1, n + 1):
    g = [a + b + x, a + c + x, b + d + x, c + d + x]
    mi = min(g)
    mx = max(g)
    dif = mx - mi
    ans += max(n-dif, 0)
print(ans)