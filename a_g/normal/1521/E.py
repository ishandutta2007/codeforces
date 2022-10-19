import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

def totalcells(n):
    return n*n-(n//2)*(n//2)
def maxfreq(n):
    return n*((n+1)//2)

t, = I()
for _ in range(t):
    m, k = I()
    a = I()
    mf = max(a)
    n = 0
    while totalcells(n) < m or maxfreq(n) < mf:
        n += 1
    print(n)
    ans = [[0]*n for _ in range(n)]
    gone = set()
    for (sx, sy) in ((1, 0), (0, 1)):
        spots = ((n+1)//2)*(n//2)
        vals = []
        z = max(range(k), key=lambda i: a[i])
        if z not in gone:
            c = min(spots, a[z])
            if c > 0:
                vals += [z]*c
                gone.add(z)
                a[z] -= c
        for i in range(k):
            if i not in gone:
                c = min(spots-len(vals), a[i])
                if c > 0:
                    vals += [i]*c
                    a[i] -= c
                    gone.add(i)
        v = 0
        for i in range(sx, n, 2):
            for j in range(sy, n, 2):
                if v < len(vals):
                    ans[i][j] = vals[v]+1
                    v += 1
    vals = []
    for i in range(k):
        vals += [i]*a[i]
    vals.sort(key=lambda x: x not in gone)
    v = 0
    for (sx, sy) in ((0, 0), (1, 0), (0, 1)):
        for i in range(sx, n, 2):
            for j in range(sy, n, 2):
                if v < len(vals) and ans[i][j] == 0:
                    ans[i][j] = vals[v]+1
                v += 1
    for row in ans:
        print(*row)