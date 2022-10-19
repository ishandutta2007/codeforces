import sys
input = sys.stdin.readline

class UnionFind():
    def __init__(self, n):
        self.n = n
        self.parents = [-1] * n
        self.group = n

    def find(self, x):
        if self.parents[x] < 0:
            return x
        else:
            self.parents[x] = self.find(self.parents[x])
            return self.parents[x]

    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)

        if x == y:
            return
        self.group -= 1
        if self.parents[x] > self.parents[y]:
            x, y = y, x

        self.parents[x] += self.parents[y]
        self.parents[y] = x

    def size(self, x):
        return -self.parents[self.find(x)]

    def same(self, x, y):
        return self.find(x) == self.find(y)

    def members(self, x):
        root = self.find(x)
        return [i for i in range(self.n) if self.find(i) == root]

    def roots(self):
        return [i for i, x in enumerate(self.parents) if x < 0]

    def group_count(self):
        return self.group

    def all_group_members(self):
        dic = {r:[] for r in self.roots()}
        for i in range(self.n):
            dic[self.find(i)].append(i)
        return dic

    def __str__(self):
        return '\n'.join('{}: {}'.format(r, self.members(r)) for r in self.roots())

def main():
    n, m = map(int, input().split())
    cnt = [0] * n
    edges = []
    for _ in range(m):
        u, v = map(int, input().split())
        u -= 1
        v -= 1
        edges.append((u, v))
        cnt[u] += 1
        cnt[v] += 1
    ind = cnt.index(max(cnt))
    UF = UnionFind(n)
    for u, v in edges:
        if u == ind or v == ind:
            print(u + 1, v + 1)
            UF.union(u, v)
    for u, v in edges:
        if not UF.same(u, v):
            print(u + 1, v + 1)
            UF.union(u, v)
    
for _ in range(1):
    main()