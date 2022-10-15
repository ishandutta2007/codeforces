n, m = map(int, raw_input().split())
k = ans = 0
while n > 0:
    ans += n
    k += n
    n = k / m
    k %= m
print ans