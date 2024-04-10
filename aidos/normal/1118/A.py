q = int(input())
for i in range(q):
    n, a, b = map(int, input().split())
    ans = 0
    if n % 2 == 1:
        n -= 1
        ans += a
    print(ans + min(n * a, (n//2) * b))