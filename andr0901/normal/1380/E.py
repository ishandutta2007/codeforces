import sys
input = sys.stdin.readline

class Dsu:
    def __init__(self, _n):
        self.n = _n
        self.p = [-1] * _n

    def get(self, v):
        if self.p[v] == -1:
            return v
        self.p[v] = self.get(self.p[v])
        return self.p[v]

    def unite(self, v, u):
        v = self.get(v)
        u = self.get(u)
        if v == u:
            return
        self.p[v] = u

n, m = map(int, input().split())
real = Dsu(m)
a = list(map(lambda x: int(x) - 1, input().split()))

idxs = [[] for i in range(n)]
for i in range(n):
    idxs[a[i]].append(i)

ans = 0
for i in range(1, n):
    if a[i] != a[i - 1]:
        ans += 1
print(ans)

for _ in range(1, m):
    v, u = map(lambda x: int(x) - 1, input().split())
    v = real.get(v)
    u = real.get(u)
    if len(idxs[v]) > len(idxs[u]):
        v, u = u, v
    real.unite(v, u)
    if v != u:
        for i in idxs[v]:
            if i >= 1 and a[i] == v and a[i - 1] == u:
                ans -= 1
            if i + 1 < n and a[i] == v and a[i + 1] == u:
                ans -= 1
        for i in idxs[v]:
            idxs[u].append(i)
            a[i] = u;
    print(ans)