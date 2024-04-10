from bisect import *
f = lambda: list(map(int, raw_input().split()))
n, m, q = f()
k = m - n + 1
a = f()
s = sum(a[0:n:2]) - sum(a[1:n:2])
b = [0] + f()
for i in range(2, m + 1, 2): b[i] = -b[i]
for i in range(m): b[i + 1] += b[i]
u = [b[j] - b[j + n] for j in range(1, k, 2)]
v = [b[j + n] - b[j] for j in range(0, k, 2)]
d = sorted(u + v)
def g(s):
    j = bisect_right(d, s)
    print(min(abs(s - d[j % k]), abs(s - d[j - 1])))
g(s)
for i in range(q):
    l, r, x = f()
    s += x * (r % 2 + l % 2 - 1)
    g(s)