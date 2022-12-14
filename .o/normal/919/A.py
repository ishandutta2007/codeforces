n, m = map(int, input().split())
p = []
for _ in range(n):
    a, b = map(int, input().split())
    p.append(float(a) / float(b))
print("%.20f" % (min(p) * m))