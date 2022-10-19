import sys
input = sys.stdin.readline

class Bit:
    def __init__(self, n):
        self.size = n
        self.n0 = 1 << (n.bit_length() - 1)
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
         
    def lower_bound(self, x):
        pos = 0
        plus = self.n0
        tot = 0
        while plus > 0:
            if pos + plus <= self.size and self.tree[pos + plus] < x:
                x -= self.tree[pos + plus]
                pos += plus
            plus //= 2
        return pos

"""
m >= p and (m - p) % 3 == 0
"""

def main():
    n = int(input())
    S = input().strip()
    ans = 0
    bits = [Bit(2 * n + 10) for _ in range(3)]
    bits[0].add(n, 1)
    p = 0
    m = 0
    for i in range(n):
        if S[i] == "+":
            p += 1
        else:
            m += 1
        
        t = (m - p) % 3
        ans += bits[t].sum(m - p + n)
        bits[t].add(m - p + n, 1)
        
    print(ans)
        
            
    
    
for _ in range(int(input())):
    main()