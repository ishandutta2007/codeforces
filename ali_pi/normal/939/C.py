rd = lambda: map(int,raw_input().split())
n = input()
a = list(rd())
s, f = rd()
d = f - s
r = s
mx = m = sum(a[:d])
for i in range(n):
    m -= a[i]
    m += a[(i + d) % n]
    if m == mx:
        r = min(r, (n - 2 - i + s) % n + 1)
    if m > mx:
        mx = m
        r = (n - 2 - i + s) % n + 1
print(r)