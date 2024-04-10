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
    se = set()
    for a in alst:
        se.add(a)
    lst = sorted(se)
    dic = {a:i for i, a in enumerate(lst)}
    alst = [dic[a] for a in alst]
    l = len(se)
    bit = Bit(l)
    ans = 0
    for a in alst:
        ans += bit.sum(a - 1)
        bit.add(a, 1)
    print(ans)
    
for _ in range(int(input())):
    main()