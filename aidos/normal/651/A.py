n, m = map(int, input().split())

cnt = 0
while n > 0 and m > 0:
    if n < m:
        n += 1
        m -= 2
    else:
        m += 1
        n -= 2
    if min(n, m) < 0:
        break
    cnt += 1
print(cnt)