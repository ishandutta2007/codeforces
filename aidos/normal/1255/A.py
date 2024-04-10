t = int(input())
for _ in range(t):
    a, b = map(int, input().split())
    d = abs(a-b)
    ans = d//5
    d %= 5
    if d > 0 and d < 3:
        ans += 1
    elif d > 0:
        ans += 2
    print(ans)