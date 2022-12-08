def main():
    def mul(a, b):
        n = len(a)
        c = [[0] * n for i in xrange(n)]
        for k in xrange(n):
            for i in xrange(n):
                for j in xrange(n):
                    c[i][j] += a[i][k] * b[k][j]
                    c[i][j] %= 1000000007
        return c
    def mulv(a, v):
        l = len(v)
        r = [0] * l
        for i in xrange(l):
            for j in xrange(l):
                r[i] += a[i][j] * v[j]
                r[i] %= 1000000007
        return r
    B = []
    for c in xrange(16):
        A = [[0] * 16 for i in xrange(16)]
        for i in xrange(c + 1):
            if i:
                A[i][i-1] = 1
            A[i][i] = 1
            if i < c:
                A[i][i+1] = 1
        l = [A]
        for j in xrange(60):
            l.append(mul(l[-1], l[-1]))
        B.append(l)
    def getb(c, l, dp):
        for i in xrange(60):
            if l >> i & 1:
                dp = mulv(B[c][i], dp)
        return dp
    n, k = map(int, raw_input().split())
    x = 0
    dp = [0] * 16
    dp[0] = 1
    for _ in xrange(n):
        a, b, c = map(int, raw_input().split())
        if b == a:
            for i in xrange(c + 1, 16):
                dp[i] = 0
        elif b >= k > a:
            dp = getb(c, k - a, dp)
            print dp[0]
            quit()
        else:
            dp = getb(c, b - a, dp)
        x = b
    print dp[0]
main()