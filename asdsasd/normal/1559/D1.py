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
    n, m1, m2 = map(int, input().split())
    UF1 = UnionFind(n)
    UF2 = UnionFind(n)
    for _ in range(m1):
        u, v = map(int, input().split())
        UF1.union(u - 1, v - 1)
    for _ in range(m2):
        u, v = map(int, input().split())
        UF2.union(u - 1, v - 1)
    ans = []
    for i in range(n):
        for j in range(i + 1, n):
            if not UF1.same(i, j) and not UF2.same(i, j):
                UF1.union(i, j)
                UF2.union(i, j)
                ans.append((i + 1, j + 1))
    print(len(ans))
    for row in ans:
        print(*row)
    
for _ in range(1):
    main()