import sys
input = sys.stdin.readline

class UnionFind():
    def __init__(self, n):
        self.n = n
        self.parents = [-1] * n
        self.group = n
        self.cnt = {1:n}

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
        
        self.cnt[-self.parents[x]] -= 1
        self.cnt[-self.parents[y]] -= 1
        self.parents[x] += self.parents[y]
        self.parents[y] = x
        self.cnt[-self.parents[x]] = self.cnt.get(-self.parents[x], 0) + 1

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
    n, d = map(int, input().split())
    UF = UnionFind(n)
    c = 1
    for _ in range(d):
        x, y = map(int, input().split())
        x -= 1
        y -= 1
        if UF.same(x, y):
            c += 1
        else:
            UF.union(x, y)
        lst = []
        for k, v in UF.cnt.items():
            lst += [k] * v
        lst.sort(reverse = True)
        print(sum(lst[:c]) - 1)
    
for _ in range(1):
    main()