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
    n, m, d = map(int, input().split())
    cnt = 0
    edges = []
    UF = UnionFind(n)
    for _ in range(m):
        u, v = map(int, input().split())
        u -= 1
        v -= 1
        edges.append((u, v))
        if u == 0 or v == 0:
            cnt += 1
        else:
            UF.union(u, v)
    if cnt < d:
        print("NO")
        return
    ans = []
    for u, v in edges:
        if not UF.same(u, v):
            ans.append((u, v))
            UF.union(u, v)
            d -= 1
    if d < 0:
        print("NO")
        exit()
    print("YES")
    UF = UnionFind(n)
    for u, v in ans:
        print(u + 1, v + 1)
        UF.union(u, v)
    for u, v in edges:
        if d > 0 and (u == 0 or v == 0):
            if not UF.same(u, v):
                UF.union(u, v)
                d -= 1
                print(u + 1, v + 1)
    for u, v in edges:
        if u != 0 and v != 0:
            if not UF.same(u, v):
                UF.union(u, v)
                print(u + 1, v + 1)
        
    
    
for _ in range(1):
    main()