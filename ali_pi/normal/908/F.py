r = g = b = R = G = B = s = u = v = 0
f = lambda k: k if k else n
for i in range(input()):
    q, c = raw_input().split()
    n = int(q)
    if c in 'RG': r, R, u = f(r), n, max(u, n - R)
    if c in 'BG': b, B, v = f(b), n, max(v, n - B)
    if c == 'G':
        if g: s -= max(u + v, n - G)
        g, G, u, v = f(g), n, 0, 0
print s + R - r + G - g + B - b