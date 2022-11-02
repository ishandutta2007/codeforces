t = int(input())
for _ in range(t):
    n, s, k = map(int, input().split())
    a = set(map(int, input().split()))
    x = s
    ans = n + 1
    while x <= n and x in a:
        x += 1
    if x <= n:
        ans = x - s
    x = s
    while x > 0 and x in a:
        x -= 1
    if x > 0:
        ans = min(s-x, ans)
    print(ans)