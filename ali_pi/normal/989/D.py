def solve(xs, vs, l, wmax):
    assert wmax >= 1
    assert l >= 1
    n = len(xs)
    assert len(vs) == n >= 1
    poss = [i for i in xrange(n) if vs[i] == +1]
    negs = [i for i in xrange(n) if vs[i] == -1]
    poss = sorted([-xs[i] for i in poss])
    negs = sorted([xs[i] + l for i in negs])
    ans = 0
    for x1 in poss:
        if wmax == 1 and x1 <= 0: continue
        lf = max(-x1, (x1 * (1 - wmax)) / (wmax + 1))
        if wmax != 1:
            lf = max(lf, -x1 * (wmax + 1) / (wmax - 1))
        L = -1
        R = len(negs)
        while R - L > 1:
            M = L + R >> 1
            if negs[M] <= lf:
                L = M
            else:
                R = M
        ans += len(negs) - R
    return ans
n, l, wmax = map(int, raw_input().split())
xs = []
vs = []
for i in xrange(n):
    x, v = map(int, raw_input().split())
    xs.append(x)
    vs.append(v)
print solve(xs, vs, l, wmax)