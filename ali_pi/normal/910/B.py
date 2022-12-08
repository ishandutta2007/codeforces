n, a, b = [input() for _ in range(3)]
d = [0]
c = 0

for i in (a, b, a, a, b, a):
    if max(d) >= i:
        d[d.index(max(d))] -= i
    else:
        c += 1
        d += [n - i]

print(c)