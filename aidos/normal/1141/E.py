h, n = map(int, input().split())
a = list(map(int, input().split()))
mi = 0
sum = 0
for i in range(n):
    sum += a[i]
    if sum < mi:
        mi = sum

if -mi < h and sum >= 0:
    print(-1)
elif sum >= 0:
    i = 0
    while i < n and h > 0:
        h += a[i]
        i += 1
    print(i)
else:
    sum = abs(sum)
    d = max((h+mi)//sum, 0)
    cnt = d * n
    h -= sum * d
    i = 0
    while h > 0:
        h += a[i]
        i = (i+1) % n
        cnt += 1
    print(cnt)