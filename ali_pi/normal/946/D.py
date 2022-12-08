n, m, k = map(int,raw_input().split())
a = [[] for i in xrange(n)]
for i in xrange(n):
    s = raw_input()
    for j in xrange(m):
        if s[j] == '1': a[i].append(j)
w = [([0] * (k + 1)) for i in xrange(n)]
for i in xrange(n):
    if len(a[i]) == 0: continue
    for j in xrange(k + 1):
        if len(a[i]) > j:
            w[i][j] = a[i][-1] - a[i][0] + 1
        else:
            w[i][j] = 0
            continue
        for x in xrange(j + 1):
            y = len(a[i]) - 1 - (j - x)
            if y >= x:
                t = a[i][y] - a[i][x] + 1
                w[i][j] = min(w[i][j], t)
dp = [[n * m for j in xrange(k + 1)] for i in xrange(n)]
for j in xrange(k + 1):
    dp[0][j] = w[0][j]
for i in xrange(1, n):
    for j in xrange(k + 1):
        for l in xrange(j + 1):
            dp[i][j] = min(dp[i][j], w[i][l] + dp[i - 1][j - l])

print (dp[-1][-1])