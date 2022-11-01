x = int(raw_input())

sol = []
invsol = []
for n in xrange(1, 1500001):
    p = (n - 1) * (n + 1) * n / 6
    p = (x + p) * 2
    d = (n + 1) * n
    if p % d == 0:
        m = p / d
        if m < n: continue
        sol.append((n, m))
        if n != m: invsol.append((m, n))
invsol.reverse()

print len(sol) + len(invsol)
for a, b in (sol + invsol):
    print a, b