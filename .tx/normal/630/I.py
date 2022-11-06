n = int(input())

ans = 0
for i in range(n - 1):
    t = 4
    if i > 0:
        t = t * 3 * (4 ** (i - 1))
    if i + 1 < n - 1:
        t = t * 3 * (4 ** (n - i - 2 - 1))

    ans += t

print(ans)