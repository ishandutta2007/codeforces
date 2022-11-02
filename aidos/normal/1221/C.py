t = int(input())
for _ in range(t):
    c, m, x = map(int, input().split())
    z = min(c, m, x)
    ans = z
    c -= z
    m -= z
    x -= z
    m = min(2 * c, m)
    c = min(2 * m, c)
    print(ans + (c+m)//3)