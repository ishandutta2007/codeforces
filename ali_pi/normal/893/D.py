f = lambda: map(int,raw_input().split())
n, d = f()
h = s = k = 0
for q in f():
    h, s = h + q, min(d, s + q)
    if h > d:
        k = -1
        break
    if q == 0:
        h = max(0, h)
        if s < 0: s, k = d, k + 1
print(k)