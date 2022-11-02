n, m = map(int, input().split())
a = set()
b = set()
for i in range(m):
    x, y = map(int, input().split())
    a.add(x)
    b.add(y)
    print((n-len(a)) * (n-len(b)))