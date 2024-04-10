n, m = map(int, input().split())
cnt = 0
for i in range(n):
    g, h = input().split()
    h = int(h)
    if g in '+':
        m += h
    elif h <= m:
        m -= h
    else:
        cnt += 1
print(m, cnt)