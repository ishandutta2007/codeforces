k, n = 0, int(input())
t = [list(map(int, input().split())) for j in range(n)]
for m, (l, r) in enumerate(t, 1):
    if not l:
        if k: t[k - 1][1], t[m - 1][0] = m, k
        k = m
        while r: k, r = r, t[r - 1][1]
for l, r in t: print(l, r)