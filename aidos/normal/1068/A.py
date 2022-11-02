n, m, k, l = map(int, input().split())
d = k + l
d += (m - d % m) % m
if d > n:
    print(-1)
else:
    print(d//m)