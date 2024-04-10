import sys
input = sys.stdin.readline

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

from collections import defaultdict
div_s = [4,9,25,49,121,169,289,361,529,841,961,1369,1681,1849,2209,2809,3481,3721,4489,5041,5329,6241,6889,7921,9409,10201,10609,11449,11881,12769,16129,17161,18769,19321,22201,22801,24649,26569,27889,29929,32041,32761,36481,37249,38809,39601,44521,49729,51529,52441,54289,57121,58081,63001,66049,69169,72361,73441,76729,78961,80089,85849,94249,96721,97969,100489,109561,113569,120409,121801,124609,128881,134689,139129,143641,146689,151321,157609,160801,167281,175561,177241,185761,187489,192721,196249,201601,208849,212521,214369,218089,229441,237169,241081,249001,253009,259081,271441,273529,292681,299209,310249,316969,323761,326041,332929,344569,351649,358801,361201,368449,375769,380689,383161,398161,410881,413449,418609,426409,434281,436921,452929,458329,466489,477481,491401,502681,516961,528529,537289,546121,552049,564001,573049,579121,591361,597529,619369,635209,654481,657721,674041,677329,683929,687241,703921,727609,734449,737881,744769,769129,776161,779689,786769,822649,829921,844561,863041,877969,885481,896809,908209,935089,942841,954529,966289,982081,994009]



def main():
    n = int(input())
    alst = list(map(int, input().split()))
    dd = defaultdict(int)
    UF = UnionFind(n)
    one = 0
    for i, a in enumerate(alst, 1):
        for d in div_s:
            while a % d == 0:
                a //= d
        if dd[a] == 0:
            dd[a] = i
        else:
            UF.union(i - 1, dd[a] - 1)
        if a == 1:
            one += 1
            
    ans1 = 0
    ans2 = 0
    for r in UF.roots():
        s = UF.size(r)
        ans1 = max(ans1, s)
        if s % 2 == 0:
            ans2 += s
    if one % 2 == 1:
        ans2 += one
    
    ans2 = max(ans1, ans2)
    for _ in range(int(input())):
        w = int(input())
        if w == 0:
            print(ans1)
        else:
            print(ans2)
    

    
for _ in range(int(input())):
    main()