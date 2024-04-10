import math
l, r, x, y = map(int, input().split())

ans = 0

if y % x != 0:
    print(0)
else:
    l = (l+x-1)//x
    r = r//x
    y //= x
    i = 1
    while i * i <= y:
        if y % i == 0:
            j = y//i
            if l <= i and i <= r and j >= l and j <= r and math.gcd(i, j) == 1:
                if i == j:
                    ans += 1
                else:
                    ans += 2
        i += 1
    print(ans)