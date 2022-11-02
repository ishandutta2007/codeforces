a, b, f, k = map(int, input().split())

cur = b
good = 1
cnt = 0
for i in range(k):
    if i % 2 == 0:
        if i == k - 1:
            if cur < f:
                good = 0
            elif cur >= a:
                cur -= a
                cnt += 0
            elif b >= a-f:
                cnt += 1
            else:
                good = 0
        elif 2 * (a-f) > b:
            good = 0
        elif cur >= 2 * a - f:
            cnt += 0
            cur -= a
        elif cur < f:
            good = 0
        else:
            cnt += 1
            cur = b - (a-f)
    else:
        if i == k - 1:
            if cur < a-f:
                good = 0
            elif cur >= a:
                cur -= a
                cnt += 0
            elif b >= f:
                cnt += 1
            else:
                good = 0
        elif 2 * f > b:
            good = 0
        elif cur >= a + f:
            cur -= a
            cnt += 0
        elif cur < a-f:
            good = 0
        else:
            cnt += 1
            cur = b - f
if good == 1:
    print(cnt)
else:
    print(-1)