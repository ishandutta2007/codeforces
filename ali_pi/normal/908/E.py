from collections import*
n, m = map(int, raw_input().split())
a = [raw_input().strip() for i in xrange(m)]
d = defaultdict(int)
for c in zip(*a):
    d[c] += 1
mod = 1000000007
b = [1, 1]
p = [1]
for i in xrange(n):
    np = [p[-1]]
    for j in xrange(i + 1):
        x = p[j] + np[-1]
        if x >= mod:
            x -= mod
        np.append(x)
    p = np
    b.append(x)
ans = 1
for c in d.viewkeys():
    x = tuple('01'[x == '0'] for x in c)
    if x not in d:
        ans = ans * b[d[c]] % mod
    elif c[0] == '0':
        ans = ans * b[d[c]] % mod * b[d[x]] % mod
print(ans)