n, a, v = input(), list(map(int, raw_input().split())), 0
c, ci, f = [0] * (n + 1), 1, [False] * (n + 1)
for ai in a:
    c[ai] += 1
for i, ai in enumerate(a):
    if c[ai] > 1:
        while c[ci]:
            ci += 1
        if ci < ai or f[ai]:
            a[i], c[ai], c[ci], v = ci, c[ai] - 1, c[ci] + 1, v + 1
        else:
            f[ai] = True
print v, ' '.join(map(str, a)),
sep='\n'