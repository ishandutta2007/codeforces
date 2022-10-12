n, m = tuple(int(i) for i in raw_input().split())
x = m / n
ans = 0
if m % n == 0:
    while x > 1:
        if x % 2 == 0:
            x /= 2
            ans += 1
        elif x % 3 == 0:
            x /= 3
            ans += 1
        else:
            ans = -1
            x = 0
else:
    ans = -1

print ans