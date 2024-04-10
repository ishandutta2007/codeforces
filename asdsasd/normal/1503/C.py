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
from collections import deque

def main():
    n = int(input())
    ac = [list(map(int, input().split())) for _ in range(n)]
    for i in range(n):
        ac[i][1] += ac[i][0]
    
    lst = []
    ans = 0
    for i, (a, c) in enumerate(ac):
        ans -= a
        lst.append((a, i, "a"))
        lst.append((c, i, "b"))
    lst.sort(key = lambda x:(x[0], x[2]))
    UF = UnionFind(n)
    a_s = deque()
    b_s = deque()
    for v, i, ab in lst:
        if ab == "a":
            a_s.append((v, i))
            if b_s:
                if not UF.same(i, b_s[0][1]):
                    av, ai = a_s.pop()
                    bv, bi = b_s.popleft()
                    UF.union(ai, bi)
                    ans += max(av, bv)
                elif not UF.same(i, b_s[-1][1]):
                    av, ai = a_s.pop()
                    bv, bi = b_s.pop()
                    UF.union(ai, bi)
                    ans += max(av, bv)
        elif ab == "b":
            b_s.append((v, i))
            if a_s:
                if not UF.same(a_s[0][1], i):
                    av, ai = a_s.popleft()
                    bv, bi = b_s.pop()
                    UF.union(ai, bi)
                    ans += max(av, bv)
                elif not UF.same(a_s[-1][1], i):
                    av, ai = a_s.pop()
                    bv, bi = b_s.pop()
                    UF.union(ai, bi)
                    ans += max(av, bv)
        
    ans += max(a_s[0][0], b_s[0][0])
    print(ans)
            
    
for _ in range(1):
    main()