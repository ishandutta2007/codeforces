import sys
input = sys.stdin.readline
MOD = 10 ** 9 + 7

class UnionFind():
    def __init__(self, n):
        self.n = n
        self.parents = [-1] * n

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
        return len(self.roots())

    def all_group_members(self):
        dic = {r:[] for r in self.roots()}
        for i in range(self.n):
            dic[self.find(i)].append(i)
        return dic

    def __str__(self):
        return '\n'.join('{}: {}'.format(r, self.members(r)) for r in self.roots())

def main():
    n, m = map(int, input().split())
    ans = []
    UF = UnionFind(m + 1)
    for i in range(1, n + 1):
        q = list(map(int, input().split()))
        if q[0] == 1:
            x = 0
            y = q[1]
        else:
            x = q[1]
            y = q[2]
        if not UF.same(x, y):
            ans.append(i)
            UF.union(x, y)
    
    cnt = 0
    for x in UF.roots():
        cnt += UF.size(x) - 1
    t = pow(2, cnt, MOD)
        
    print(t, len(ans))
    print(*ans)
        
for _ in range(1):
    main()