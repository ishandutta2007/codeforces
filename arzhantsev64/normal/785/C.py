n, m = list(map(int, input().split()))
l = -1
r = int(1e18 + 10)
while r - l != 1:
    t = (r + l) // 2
    eaten = t
    if (t - 1 > m):
        eaten += (t - 1 - m) * (t - m) // 2
    if eaten >= n:
        r = t
    else:
        l = t
print(r)