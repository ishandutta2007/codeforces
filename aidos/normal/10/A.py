n, P1, P2, P3, T1, T2 = map(int, input().split())
l = []
r = []
ans = 0
for i in range(n):
    x, y = map(int, input().split())
    l += [x]
    r += [y]
    ans += (y-x) * P1

for i in range(1, n):
    h = l[i] - r[i-1]
    if h < T1:
        ans += P1 * h
    else:
        ans += P1 * T1
        h -= T1
        if h < T2:
            ans += h * P2
        else:
            ans += T2 * P2
            h -= T2
            ans += h * P3
print(ans)