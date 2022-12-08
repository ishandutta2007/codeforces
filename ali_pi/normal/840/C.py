from collections import*
n = int(raw_input())
a = [0] * 34000
ps = []
for i in xrange(2, 34000):
    if a[i]:
        continue
    ps.append(i * i)
    j = i * i
    while j < 34000:
        a[j] = 1
        j += i
a = map(int, raw_input().split())
b = defaultdict(int)
for x in a:
    for p in ps:
        while x % p == 0:
            x /= p
    b[x] += 1
b = b.values()
mod = 1000000007
f = [1] * (n + 1)
for i in xrange(2, n + 1):
    f[i] = f[i-1] * i % mod
inv = [1] * (n + 1)
invf = [1] * (n + 1)
for i in xrange(2, n + 1):
    inv[i] = mod - mod / i * inv[mod%i] % mod
    invf[i] = invf[i-1] * inv[i] % mod
def mul(pl, pr):
    res = [0] * (len(pl) + len(pr) - 1)
    for i, x in enumerate(pl):
        for j, y in enumerate(pr):
            res[i+j] += x * y
            res[i+j] %= mod
    return res
qs = [1]
for x in b:
    q = []
    for i in xrange(x):
        t = f[x-1] * invf[x-1-i] * invf[i] * invf[x-i] % mod
        q.append(t)
    qs = mul(q, qs)
ans = 0
for i in xrange(len(qs)):
    t = f[n-i] * qs[i] % mod
    if i & 1:
        t = mod - t
    ans += t
for x in b:
    ans = ans * f[x] % mod
print ans