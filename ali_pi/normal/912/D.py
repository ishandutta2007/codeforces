def getb(a, b, r, k):
    bc = b[:]
    for i in xrange(len(b) - 2, -1, -1):
        bc[i] += bc[i+1]
    lo = 0
    hi = r * r + 1
    la = len(a) - 1
    lb = len(b)
    while lo + 1 < hi:
        mid = (lo + hi) / 2
        t = 0
        for i in xrange(la, 0, -1):
            s = (mid + i - 1) / i
            if s >= lb:
                break
            t += a[i] * bc[s]
        if t < k:
            hi = mid
        else:
            lo = mid
    return lo
def main():
    n, m, r, k = map(int, raw_input().split())
    if n > m:
        n, m = m, n
    def g(n, r):
        res = [0] * (r + 1)
        for i in xrange(n):
            L = max(0, i + 1 - r)
            R = min(n - r, i)
            res[R-L+1] += 1
        while not res[-1]:
            res.pop()
        return res
    nt = g(n, r)
    mt = g(m, r)
    b = getb(nt, mt, r, k)
    ans = 0
    for i in xrange(len(nt) - 1, 0, -1):
        for j in xrange(len(mt) - 1, 0, -1):
            x = i * j
            if i * j <= b:
                break
            ans += 1. * x * nt[i] * mt[j]
            k -= nt[i] * mt[j]
    ans += 1. * b * k
    print "%.12f" % (ans / (n - r + 1) / (m - r + 1))
main()