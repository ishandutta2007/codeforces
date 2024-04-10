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
    input()
    n, m = map(int, input().split())
    edges = [None] * m
    ng = [False] * m
    for i in range(m):
        u, v, w = map(int, input().split())
        edges[i] = [u - 1, v - 1, w]
    ans = 0
    for i in range(29, -1, -1):
        UF = UnionFind(n)
        for j in range(m):
            if ng[j]:
                continue
            u, v, w = edges[j]
            if not w >> i & 1:
                UF.union(u, v)
        if UF.group_count() == 1:
            for j in range(m):
                w = edges[j][2]
                if w >> i & 1:
                    ng[j] = True
        else:
            ans += 1 << i
    print(ans)
    
for _ in range(int(input())):
    main()