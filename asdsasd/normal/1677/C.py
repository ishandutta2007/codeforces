import sys
input = sys.stdin.readline

class UnionFind:
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
    n = int(input())
    ca = list(map(int, input().split()))
    cb = list(map(int, input().split()))
    UF = UnionFind(n)
    for a, b in zip(ca, cb):
        UF.union(a - 1, b - 1)
    G = []
    for r in UF.roots():
        if UF.size(r) != 1:
            G.append(UF.size(r) // 2)
    l = 1
    r = n
    ans = 0
    for g in G:
        lst = []
        for _ in range(g):
            lst.append(l)
            l += 1
            lst.append(r)
            r -= 1
        for i in range(len(lst)):
            ans += abs(lst[i] - lst[i - 1])
    print(ans)

    
for _ in range(int(input())):
    main()