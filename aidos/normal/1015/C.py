n, m = map(int, input().split())
a = []
for i in range(n):
    x, y = map(int, input().split())
    a.append(x-y)
    m -= y
cnt = n
a = sorted(a)
for i in range(n):
    if a[i] <= m:
        m -= a[i]
        cnt -= 1
if m < 0:
    cnt = -1
print(cnt)