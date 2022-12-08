ri = lambda: map(int, raw_input().split())

n, m, a, d = ri()
t = ri()

d += 1

i = 1
j = 0
l = 0
ans = 0

v = (d + a - 1) / a

while i <= n or j < m:
    if l > 0 and i <= n and i * a < l + d:
        i = min(n + 1, (l + d + a - 1) / a)
        continue
    if l > 0 and j < m and t[j] < l + d:
        j += 1
        continue
    if j >= m:
        x = n - i + 1
        num = (x + v - 1) / v
        ans += num
        i += num * v
        l = (i - v) * a
        continue
    if i > n or a * i >= t[j]:
        l = t[j]
        ans += 1
        continue
    else:
        e = min(t[j] / a, n)
        x = e - i + 1
        num = (x + v - 1) / v
        ans += num
        i += num * v
        l = (i - v) * a
print ans