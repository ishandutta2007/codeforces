f = lambda: map(int, raw_input().split())
a, b, h, w, n = f()
c = sorted(list(f()), key=lambda x: -x)
d = {(h, w), (w, h)}
for i, q in enumerate([1] + c):
    for u, v in d.copy():
        h, w = u, v * q
        if a <= w and b <= h or a <= h and b <= w:
            print(i)
            exit()
        d.add((h, w))
        d.add((w, h))
print(-1)