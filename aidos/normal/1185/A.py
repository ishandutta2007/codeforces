a = list(map(int, input().split()))
b = a[:3]
d = a[3]
b = sorted(b)
ans = 0
if b[1] - b[0] < d:
    ans += d - (b[1] - b[0])
if b[2] - b[1] < d:
    ans += d - (b[2] - b[1])
print(ans)