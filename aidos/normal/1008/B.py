n = int(input())
last = 10**10
for i in range(n):
    h, w = map(int, input().split())
    cur = -10 ** 10
    if h <= last:
        cur = max(cur, h)
    if w <= last:
        cur = max(cur, w)
    last = cur
if last < 0:
    print('NO')
else:
    print('YES')