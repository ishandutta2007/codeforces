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



def main():
    n = int(input())
    A = list(map(int, input().split()))
    ans = 0
    bit = Bit(n)
    for i, a in enumerate(A):
        a -= 1
        ans += i - bit.sum(a - 1)
        bit.add(a, 1)
    print(ans)

for _ in range(int(input())):
    main()