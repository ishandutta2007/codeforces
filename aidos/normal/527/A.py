n, m = map(int, input().split())
ans = 0
while n > 0 and m > 0:
    ans += n//m
    n, m = m, n % m
print(ans)