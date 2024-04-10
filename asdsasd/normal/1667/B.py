import sys
input = sys.stdin.readline

class SegTree:
    def __init__(self, n, e, ope, lst=[]):
        self.N0 = 2 ** (n - 1).bit_length()
        self.e = e
        self.ope = ope
        self.data = [e] * (2 * self.N0)
        if lst:
            for i in range(n):
                self.data[self.N0 + i] = lst[i]
            for i in range(self.N0 - 1, 0, -1):
                self.data[i] = self.ope(self.data[2 * i], self.data[2 * i + 1])
    
    def build(self):
        for i in range(self.N0 - 1, 0, -1):
            self.data[i] = self.ope(self.data[2 * i], self.data[2 * i + 1])
                
    def update(self, i, x): #a_ix
        i += self.N0
        self.data[i] = x
        while i > 1:
            i >>= 1
            self.data[i] = self.ope(self.data[2 * i], self.data[2 * i + 1])
    
    def add(self, i, x):
        self.update(i, x + self.get(i))

    def set(self, i, x):
        self.data[self.N0 + i] = x
    
    def query(self, l, r): #[l, r)
        if r <= l:
            return self.e
        lres = self.e
        rres = self.e
        l += self.N0
        r += self.N0
        while l < r:
            if l & 1:
                lres = self.ope(lres, self.data[l])
                l += 1
            if r & 1:
                r -= 1
                rres = self.ope(self.data[r], rres)
            l >>= 1
            r >>= 1
        return self.ope(lres, rres)
    
    def get(self, i): #a_i
        return self.data[self.N0 + i]

def main(n, A):
    cum = [0]
    for a in A:
        cum.append(cum[-1] + a)
    se = set(cum)
    dic = {s:i for i, s in enumerate(sorted(se))}
    l = len(se)
    inf = 1 << 30
    seg1 = SegTree(l, -inf, max)
    seg1.update(dic[0], 0)
    seg2 = [-inf] * l
    seg2[dic[0]] = 0
    seg3 = SegTree(l, -inf, max)
    seg3.update(dic[0], 0)
    
    for i, c in enumerate(cum[1:], 1):
        c = dic[c]
        low = seg1.query(0, c)
        same = seg2[c]
        upp = seg3.query(c + 1, l)
        ma = max(low + i, same, upp - i)
        if ma - i > seg1.get(c):
            seg1.update(c, ma - i)
        if ma > seg2[c]:
            seg2[c] = ma
        if ma + i > seg3.get(c):
            seg3.update(c, ma + i)
        
    return ma
    

def stupid(n, A):
    ans = -n
    for bit in range(1 << (n - 1)):
        tmp = 0
        tot = 0
        bef = -1
        for i in range(n - 1):
            tmp += A[i]
            if bit >> i & 1:
                if tmp > 0:
                    tot += i - bef
                elif tmp == 0:
                    pass
                else:
                    tot -= i - bef
                tmp = 0
                bef = i
        i = n - 1
        tmp += A[i]
        if tmp > 0:
            tot += i - bef
        elif tmp == 0:
            pass
        else:
            tot -= i - bef
        ans = max(ans, tot)
    return ans

for _ in range(int(input())):
    n = int(input())
    A = list(map(int, input().split()))
    print(main(n, A))

exit()
#n, A = 6, [-3, 0, -8, -4, 8, -3],
#print(main(n, A))
#exit()


import random
random.seed(0)
for _ in range(1000):
    n = 6
    A = [random.randrange(-10, 10) for _ in range(n)]
    assert main(n, A) == stupid(n, A), (n, A, main(n, A), stupid(n, A))