import sys
input = sys.stdin.readline

class Bit:
    def __init__(self, n):
        self.size = n
        self.tree = [0] * (n + 1)
    
    def range_sum(self, l, r):
        return self.sum(r) - self.sum(l - 1)
        
        
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
    n = int(input())
    alst = list(map(int, input().split()))
    bit1 = Bit(n + 1)
    bit2 = Bit(n + 1)
    for a in alst:
        bit1.add(a, 1)
    ans = []
    l = 0
    r = n - 1
    pos = 1
    while r != l:
        if bit1.get(pos) >= 1 and bit1.sum(pos - 1) == 0 and bit2.sum(pos - 1) == pos - 1:
            ans.append("1")
        else:
            ans += ["0"] * (n - len(ans) - 1)
            break
        if alst[l] <= alst[r]:
            num = alst[l]
            l += 1
        else:
            num = alst[r]
            r -= 1
        bit1.add(num, -1)
        if bit2.get(num) == 0:
            bit2.add(num, 1)
        pos += 1
    lst = [i for i in range(1, n + 1)]
    alst.sort()
    for a, b in zip(alst, lst):
        if a != b:
            ans.append("0")
            print("".join(ans[::-1]))
            return
    ans.append("1")
    print("".join(ans[::-1]))
    
    
for _ in range(int(input())):
    main()