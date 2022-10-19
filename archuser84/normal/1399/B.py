for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    x = min(a)
    y = min(b)
    ans = 0
    for i in range(n):
        ans += max(a[i] - x, b[i] - y)
    print(ans)