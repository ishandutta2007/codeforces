import sys
input = sys.stdin.readline

class Bit:
    def __init__(self, n):
        self.size = n
        self.tree = [0] * (n + 1)
    
    def range_sum(self, l, r):
        return self.sum(r - 1) - self.sum(l - 1)
        
        
    def sum(self, i):
        i += 1
        s = 0
        while i > 0:
            s += self.tree[i]
            i -= i & -i
        return s
        
    def get(self, i):
        return self.sum(i) - self.sum(i - 1)
 
    def add(self, i, x):
        i += 1
        while i <= self.size:
            self.tree[i] += x
            i += i & -i
 
def main():
    n, m = map(int, input().split())
    alst = list(map(int, input().split()))
    alst = [(a, i) for i, a in enumerate(alst)]
    alst.sort(key = lambda x:(x[0], x[1]))
    row = [[] for _ in range(n)]
    for j, (a, i) in enumerate(alst):
        row[j // m].append((i, a))
    ans = 0
    for alst in row:
        alst.sort()
        se = set()
        alst = [a for i, a in alst]
        se = set(alst)
        lst = sorted(se)
        dic = {a:i for i, a in enumerate(lst)}
        alst = [dic[a] for a in alst]
        l = len(lst)
        bit = Bit(l)
        for a in alst:
            ans += bit.sum(a - 1)
            bit.add(a, 1)
    print(ans)
    
    
    
for _ in range(int(input())):
    main()