import sys
input = sys.stdin.readline
MOD = 10 ** 9 + 7

class UnionFind:
    def __init__(self, n):
        self.n = n
        self.parents = [-1] * n
        self.group = n
        self.used = [False] * n

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
        self.used[x] |= self.used[y]

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
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    D = list(map(int, input().split()))
    UF = UnionFind(n)
    for a, b in zip(A, B):
        if a == b:
            UF.used[a - 1] = True
    for d in D:
        if d != 0:
            UF.used[d - 1] = True
    for a, b in zip(A, B):
        UF.union(a - 1, b - 1)
    ans = 1
    for r in UF.roots():
        if not UF.used[r]:
            ans *= 2
            ans %= MOD
    print(ans)



    
for _ in range(int(input())):
    main()