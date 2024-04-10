t = int(input())

for i in range(t):
    n, m = map(int, input().split())
    n //= m
    s = 0
    ans = 0
    for i in range(10):
        s += (i * m) % 10
        if i == n % 10:
            ans += s
    ans += s * (n//10)
    print(ans)